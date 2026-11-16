// Undo / redo as two stacks of snapshots. The caller decides what a snapshot is. Undo and redo
// take a function that captures the current state matching a snapshot, so the change can be put
// back the other way.
export class History {
  constructor(limit = 200) {
    this.limit = limit;
    this.undoStack = [];
    this.redoStack = [];
  }

  /** Call before a change, with the state it changes from. */
  record(snapshot) {
    this.undoStack.push(snapshot);
    if (this.undoStack.length > this.limit) this.undoStack.shift();
    this.redoStack.length = 0;
  }

  /** The snapshot to restore, or null when there is nothing to undo. */
  undo(capture) {
    if (this.undoStack.length === 0) return null;
    const snapshot = this.undoStack.pop();
    this.redoStack.push(capture(snapshot));
    return snapshot;
  }

  redo(capture) {
    if (this.redoStack.length === 0) return null;
    const snapshot = this.redoStack.pop();
    this.undoStack.push(capture(snapshot));
    return snapshot;
  }
}
