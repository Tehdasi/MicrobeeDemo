// Saves edits in the background. Each kind of edit is a keyed job; scheduling a key again
// replaces its job, and jobs run a moment after edits stop. A job reads the current state when it
// runs, so a burst of edits becomes one request. If the server is unreachable the jobs are kept
// and retried with backoff; a request the server refuses is reported and dropped, so it cannot
// hold up the saves behind it.
import { isRetryable } from './api.js';
import { emit } from './bus.js';

const DELAY = 250;
const MAX_BACKOFF = 30000;

const jobs = new Map();
let timer = 0;
let running = false;
let failures = 0;
let problem = null; // { message, retrying }

export function schedule(key, job) {
  jobs.set(key, job);
  arm(DELAY);
  report();
}

export function cancel(key) {
  jobs.delete(key);
  report();
}

/** Runs everything waiting now (Ctrl+S). */
export function flush() {
  arm(0);
}

export function isIdle() {
  return !running && jobs.size === 0;
}

/** 'saved', 'pending', 'saving', 'offline' (retrying) or 'error' (the last save was refused). */
export function status() {
  if (problem?.retrying) return { state: 'offline', message: problem.message };
  if (running) return { state: 'saving' };
  if (jobs.size > 0) return { state: 'pending' };
  if (problem) return { state: 'error', message: problem.message };
  return { state: 'saved' };
}

function arm(delay) {
  clearTimeout(timer);
  timer = setTimeout(run, delay);
}

async function run() {
  // A run already going picks up anything scheduled meanwhile when it finishes.
  if (running) return;
  running = true;
  const batch = [...jobs];
  jobs.clear();
  report();

  let unreachable = false;
  for (const [key, job] of batch) {
    if (unreachable) {
      if (!jobs.has(key)) jobs.set(key, job);
      continue;
    }
    try {
      await job();
      failures = 0;
      problem = null;
    } catch (error) {
      if (isRetryable(error)) {
        unreachable = true;
        failures++;
        // A newer job for the same key, scheduled meanwhile, supersedes this one.
        if (!jobs.has(key)) jobs.set(key, job);
        problem = { message: error.status ? error.message : 'The server cannot be reached.', retrying: true };
      } else {
        console.warn(`Save refused (${key}):`, error.message);
        problem = { message: error.message, retrying: false };
      }
    }
  }

  running = false;
  if (jobs.size > 0) arm(unreachable ? Math.min(MAX_BACKOFF, 500 * 2 ** failures) : DELAY);
  report();
}

function report() {
  emit('save', status());
}

window.addEventListener('beforeunload', event => {
  if (!isIdle()) event.preventDefault();
});
