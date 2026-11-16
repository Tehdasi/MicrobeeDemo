// wavetext_font at a glance: the string in its font, every tile, and the export.
import { on } from '../bus.js';
import { charGrid } from '../char-grid.js';
import { h } from '../dom.js';
import { exportPanel } from '../export-panel.js';
import { state } from '../state.js';
import { textPreview } from '../text-preview.js';

/** "115 characters, 30 different: 595 bytes exported". */
export function fontStats() {
  const { text, bitmapBytes } = state.font;
  const distinct = new Set(text).size;
  return `${text.length} characters, ${distinct} different: `
    + `${(text.length + distinct * bitmapBytes).toLocaleString()} bytes exported`;
}

export function fontOverview(el) {
  const preview = textPreview();
  const grid = charGrid(code => { location.hash = `#/wavetext_font/tiles/${code}`; });
  const exports = exportPanel();
  const stats = h('p', { class: 'muted' }, fontStats());

  el.replaceChildren(
    h('h1', {}, 'wavetext_font'),
    h('p', { class: 'lede' },
      'The message the wave text effect (src/wavetext.c) scrolls, and the monochrome 8 × 10 font it is drawn in. ',
      'Edit the ', h('a', { href: '#/wavetext_font/string' }, 'string'), ' or the ',
      h('a', { href: '#/wavetext_font/tiles' }, 'tiles'), '.'),
    h('section', {}, h('h2', {}, 'Preview'), stats, preview.el),
    h('section', {}, h('h2', {}, 'Tiles'), h('p', { class: 'muted' }, 'Click a character to edit it.'), grid.el),
    h('section', {}, h('h2', {}, 'Export'), exports.el),
  );

  const off = on('text', () => { stats.textContent = fontStats(); });
  return {
    unmount() {
      off();
      preview.dispose();
      grid.dispose();
      exports.dispose();
    },
  };
}
