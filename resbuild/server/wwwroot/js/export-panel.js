// Where res.h and res.c are written, whether they have caught up with the edits, and what is in
// them. Refreshes after saves (the server writes a second after edits stop).
import { api } from './api.js';
import { on } from './bus.js';
import { h } from './dom.js';

const open = new Set(); // which files are expanded, kept across refreshes and pages

export function exportPanel() {
  const el = h('div', { class: 'export-panel' }, h('p', { class: 'muted' }, 'Loading…'));
  let timer = 0;
  let disposed = false;

  async function refresh() {
    clearTimeout(timer);
    try {
      const status = await api.exportStatus();
      if (disposed) return;
      render(status);
      const settled = !status.pending && status.files.every(file => file.upToDate);
      if (!settled) timer = setTimeout(refresh, status.error ? 3000 : 800);
    } catch (error) {
      if (disposed) return;
      el.replaceChildren(h('p', { class: 'problem' }, `Could not load the export: ${error.message}`));
      timer = setTimeout(refresh, 3000);
    }
  }

  function render(status) {
    const allCurrent = status.files.every(file => file.upToDate);
    const overall = status.pending
      ? h('span', { class: 'badge warn' }, 'waiting to write')
      : allCurrent ? h('span', { class: 'badge good' }, 'up to date') : h('span', { class: 'badge bad' }, 'not written');

    const parts = [
      h('p', {}, 'Written to ', h('code', {}, status.directory), ' ', overall,
        status.writtenAt ? h('span', { class: 'muted' }, ` last written ${new Date(status.writtenAt).toLocaleTimeString()}`) : null),
      status.error ? h('p', { class: 'problem' }, status.error) : null,
      ...status.files.map(file => {
        const lines = file.content.split('\n').length - 1;
        const details = h('details', { class: 'export-file', open: open.has(file.name) },
          h('summary', {},
            h('code', {}, file.name),
            h('span', { class: 'muted' }, ` ${lines} lines, ${file.content.length.toLocaleString()} bytes `),
            file.upToDate ? null : h('span', { class: 'badge warn' }, 'differs from disk')),
          h('pre', { class: 'code' }, file.content));
        details.addEventListener('toggle', () => (details.open ? open.add(file.name) : open.delete(file.name)));
        return details;
      }),
    ];
    el.replaceChildren(...parts.filter(Boolean));
  }

  const off = on('save', ({ state }) => {
    if (state !== 'saved') return;
    clearTimeout(timer);
    timer = setTimeout(refresh, 1200);
  });
  refresh();

  return {
    el,
    dispose() {
      disposed = true;
      clearTimeout(timer);
      off();
    },
  };
}
