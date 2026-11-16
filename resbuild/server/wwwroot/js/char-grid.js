// Every character of the font as a grid of small tiles. A dot marks characters the string uses;
// it turns amber when that character has no tile yet.
import { on } from './bus.js';
import { h } from './dom.js';
import { drawTile } from './render.js';
import { hasTile, state, tileRows } from './state.js';
import { charLabel, tileAspect } from './util.js';

const CELL_SCALE = 3;
export const GRID_COLUMNS = 16;

export function charGrid(onPick) {
  const { firstCode, lastCode, tileWidth, tileHeight } = state.font;
  const cells = new Map();
  const el = h('div', { class: 'char-grid', style: `--columns: ${GRID_COLUMNS}` });

  for (let code = firstCode; code <= lastCode; code++) {
    const canvas = h('canvas', { class: 'pixels' });
    const button = h('button', {
      class: 'char-cell',
      title: `${charLabel(code)} (${code})`,
      onclick: () => onPick(code),
    }, canvas, h('span', { class: 'char-label' }, charLabel(code)));
    cells.set(code, { button, canvas });
    el.append(button);
  }

  function drawCell(code) {
    drawTile(cells.get(code).canvas, tileRows(code), tileWidth * CELL_SCALE, tileHeight * CELL_SCALE * tileAspect());
  }

  function mark() {
    const used = new Set(Array.from(state.font.text, character => character.charCodeAt(0)));
    for (const [code, { button }] of cells) {
      button.classList.toggle('used', used.has(code));
      button.classList.toggle('undrawn', used.has(code) && code !== 32 && !hasTile(code));
    }
  }

  function drawAll() {
    for (const code of cells.keys()) drawCell(code);
  }

  const offs = [
    on('tile', code => {
      drawCell(code);
      mark();
    }),
    on('text', mark),
    on('settings', drawAll),
  ];
  drawAll();
  mark();

  return {
    el,
    select(code) {
      for (const [other, { button }] of cells) button.classList.toggle('selected', other === code);
      cells.get(code)?.button.scrollIntoView({ block: 'nearest' });
    },
    dispose() {
      offs.forEach(off => off());
    },
  };
}
