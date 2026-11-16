// Small helpers shared by the views.
import { emit } from './bus.js';

/** The cells on a straight line from (x0, y0) to (x1, y1), so fast drags leave no gaps. */
export function* line(x0, y0, x1, y1) {
  const dx = Math.abs(x1 - x0);
  const dy = -Math.abs(y1 - y0);
  const sx = x0 < x1 ? 1 : -1;
  const sy = y0 < y1 ? 1 : -1;
  let error = dx + dy;
  for (;;) {
    yield [x0, y0];
    if (x0 === x1 && y0 === y1) return;
    const doubled = 2 * error;
    if (doubled >= dy) {
      error += dy;
      x0 += sx;
    }
    if (doubled <= dx) {
      error += dx;
      y0 += sy;
    }
  }
}

export function clamp(value, low, high) {
  return Math.min(high, Math.max(low, value));
}

/** A character as a label: itself, or "space". */
export function charLabel(code) {
  return code === 32 ? 'space' : String.fromCharCode(code);
}

export function hex2(value) {
  return `0x${value.toString(16).padStart(2, '0')}`;
}

/** Wraps fn so calls made within one frame run it once, at the next frame. */
export function perFrame(fn) {
  let queued = false;
  return () => {
    if (queued) return;
    queued = true;
    requestAnimationFrame(() => {
      queued = false;
      fn();
    });
  };
}

// ------------------------------------------------------------ settings

const TALL_KEY = 'resbuild.tallTiles';

function readTall() {
  try {
    return localStorage.getItem(TALL_KEY) !== 'false';
  } catch {
    return true;
  }
}

/** How font tiles are shown. Remembered in this browser; tells the views with a 'settings' event. */
export const settings = { tallTiles: readTall() };

export function setTallTiles(tall) {
  settings.tallTiles = tall;
  try {
    localStorage.setItem(TALL_KEY, String(tall));
  } catch {
    // Not remembered, but still applied.
  }
  emit('settings');
}

/** How many times taller than wide font pixels are drawn. */
export function tileAspect() {
  return settings.tallTiles ? 2 : 1;
}
