// A tiny pub/sub, so views hear about edits made elsewhere (another view, undo, the tree).
const handlers = new Map();

/** Subscribes; returns the function that unsubscribes. */
export function on(event, handler) {
  if (!handlers.has(event)) handlers.set(event, new Set());
  handlers.get(event).add(handler);
  return () => handlers.get(event).delete(handler);
}

export function emit(event, detail) {
  for (const handler of handlers.get(event) ?? []) handler(detail);
}
