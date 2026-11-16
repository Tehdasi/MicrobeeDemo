// The font's tiles: the grid of characters on the left, the selected tile's pixels on the right.
import { on } from '../bus.js';
import { charGrid, GRID_COLUMNS } from '../char-grid.js';
import { h, isTyping } from '../dom.js';
import { pixelBuffer, putTile, sizeCanvas } from '../render.js';
import { blankRows, fontHistory, setTile, state, tileRows } from '../state.js';
import { textPreview } from '../text-preview.js';
import { charLabel, clamp, hex2, line, perFrame, setTallTiles, settings, tileAspect } from '../util.js';

let lastCode = 65; // 'A'
let clipboard = null;

export function tilesView(el, params) {
  const { firstCode, lastCode: finalCode, tileWidth, tileHeight } = state.font;
  let code = params.code ?? lastCode;
  let stroke = null;

  const grid = charGrid(select);
  const canvas = h('canvas', { class: 'pixels tile-canvas' });
  const title = h('h2', { class: 'tile-title' });
  const usage = h('p', { class: 'muted' });
  const rowsText = h('code', { class: 'tile-rows' });
  const preview = textPreview();
  const tall = h('input', { type: 'checkbox', checked: settings.tallTiles, onchange: () => setTallTiles(tall.checked) });

  const button = (label, action, hint) => h('button', { onclick: action, title: hint }, label);
  const tools = h('div', { class: 'toolbar' },
    button('Clear', () => apply(() => blankRows()), 'Delete'),
    button('Invert', () => apply(rows => rows.map(row => ~row & 0xff))),
    button('Flip ↔', () => apply(rows => rows.map(flipRow))),
    button('Flip ↕', () => apply(rows => rows.reverse())),
    h('span', { class: 'toolbar-gap' }),
    button('←', () => shift(-1, 0), 'Shift+Left'),
    button('→', () => shift(1, 0), 'Shift+Right'),
    button('↑', () => shift(0, -1), 'Shift+Up'),
    button('↓', () => shift(0, 1), 'Shift+Down'),
    h('span', { class: 'toolbar-gap' }),
    button('Undo', undo, 'Ctrl+Z'),
    button('Redo', redo, 'Ctrl+Y'),
    button('Copy', copy, 'Ctrl+C'),
    button('Paste', paste, 'Ctrl+V'),
  );

  // ------------------------------------------------------------ drawing

  function cellSize() {
    const width = settings.tallTiles ? 24 : 32;
    return { width, height: width * tileAspect() };
  }

  const draw = perFrame(() => {
    const cell = cellSize();
    const width = tileWidth * cell.width;
    const height = tileHeight * cell.height;
    const context = sizeCanvas(canvas, width, height);
    const buffer = pixelBuffer(tileWidth, tileHeight);
    const rows = tileRows(code);
    putTile(buffer, rows);
    buffer.drawTo(context, 0, 0, width, height);

    context.fillStyle = 'rgba(128, 160, 255, 0.25)';
    for (let x = 1; x < tileWidth; x++) context.fillRect(x * cell.width, 0, 1, height);
    for (let y = 1; y < tileHeight; y++) context.fillRect(0, y * cell.height, width, 1);

    title.textContent = `${charLabel(code)}  ·  ${code} (${hex2(code)})`;
    const uses = Array.from(state.font.text).filter(character => character.charCodeAt(0) === code).length;
    usage.textContent = uses === 0 ? 'Not in the string, so not exported.' : `Used ${uses} time${uses === 1 ? '' : 's'} in the string.`;
    rowsText.textContent = rows.map(hex2).join(', ');
  });

  // ------------------------------------------------------------ editing

  function select(next) {
    code = clamp(next, firstCode, finalCode);
    lastCode = code;
    grid.select(code);
    history.replaceState(null, '', `#/wavetext_font/tiles/${code}`);
    draw();
  }

  /** Replaces the tile with fn(rows) as one undo step. */
  function apply(fn) {
    const before = tileRows(code);
    const after = fn(before.slice());
    if (after.every((row, y) => row === before[y])) return;
    fontHistory.record({ code, rows: before });
    setTile(code, after);
  }

  function flipRow(row) {
    let flipped = 0;
    for (let x = 0; x < 8; x++) if (row & (0x80 >> x)) flipped |= 1 << x;
    return flipped;
  }

  /** Moves every pixel one step, wrapping around. */
  function shift(dx, dy) {
    apply(rows => {
      if (dx < 0) rows = rows.map(row => ((row << 1) | (row >> 7)) & 0xff);
      if (dx > 0) rows = rows.map(row => ((row >> 1) | (row << 7)) & 0xff);
      if (dy < 0) rows.push(rows.shift());
      if (dy > 0) rows.unshift(rows.pop());
      return rows;
    });
  }

  function restore(snapshot) {
    if (!snapshot) return;
    setTile(snapshot.code, snapshot.rows);
    if (snapshot.code !== code) select(snapshot.code);
  }

  const capture = snapshot => ({ code: snapshot.code, rows: tileRows(snapshot.code) });
  function undo() { restore(fontHistory.undo(capture)); }
  function redo() { restore(fontHistory.redo(capture)); }
  function copy() { clipboard = tileRows(code); }
  function paste() { if (clipboard) apply(() => clipboard.slice()); }

  function cellAt(event) {
    const box = canvas.getBoundingClientRect();
    return {
      x: clamp(Math.floor(((event.clientX - box.left) / box.width) * tileWidth), 0, tileWidth - 1),
      y: clamp(Math.floor(((event.clientY - box.top) / box.height) * tileHeight), 0, tileHeight - 1),
    };
  }

  function paint(event) {
    const to = cellAt(event);
    const from = stroke.last ?? to;
    const rows = tileRows(code);
    let changed = false;
    for (const [x, y] of line(from.x, from.y, to.x, to.y)) {
      const bit = 0x80 >> x;
      const next = stroke.on ? rows[y] | bit : rows[y] & ~bit;
      if (next !== rows[y]) {
        rows[y] = next;
        changed = true;
      }
    }
    stroke.last = to;
    if (!changed) return;
    if (!stroke.recorded) {
      fontHistory.record({ code, rows: tileRows(code) });
      stroke.recorded = true;
    }
    setTile(code, rows);
  }

  canvas.addEventListener('pointerdown', event => {
    if (event.button !== 0 && event.button !== 2) return;
    event.preventDefault();
    canvas.setPointerCapture(event.pointerId);
    stroke = { on: event.button === 0 && !event.ctrlKey, last: null, recorded: false };
    paint(event);
  });
  canvas.addEventListener('pointermove', event => { if (stroke) paint(event); });
  const endStroke = () => { stroke = null; };
  canvas.addEventListener('pointerup', endStroke);
  canvas.addEventListener('pointercancel', endStroke);
  canvas.addEventListener('contextmenu', event => event.preventDefault());

  function onKey(event) {
    if (isTyping(event)) return;
    const ctrl = event.ctrlKey || event.metaKey;
    const key = event.key;
    let handled = true;
    if (ctrl && key.toLowerCase() === 'z') event.shiftKey ? redo() : undo();
    else if (ctrl && key.toLowerCase() === 'y') redo();
    else if (ctrl && key.toLowerCase() === 'c') copy();
    else if (ctrl && key.toLowerCase() === 'v') paste();
    else if (ctrl || event.altKey) handled = false;
    else if (key === 'Delete' || key === 'Backspace') apply(() => blankRows());
    else if (key.startsWith('Arrow')) {
      const [dx, dy] = { ArrowLeft: [-1, 0], ArrowRight: [1, 0], ArrowUp: [0, -1], ArrowDown: [0, 1] }[key];
      if (event.shiftKey) shift(dx, dy);
      else select(code + dx + dy * GRID_COLUMNS);
    } else if (key.length === 1 && key.charCodeAt(0) >= firstCode && key.charCodeAt(0) <= finalCode) {
      // Typing a character picks its tile.
      select(key.charCodeAt(0));
    } else handled = false;
    if (handled) event.preventDefault();
  }
  document.addEventListener('keydown', onKey);

  const offs = [
    on('tile', changed => { if (changed === code) draw(); }),
    on('text', draw),
    on('settings', draw),
  ];

  el.replaceChildren(
    h('h1', {}, 'wavetext_font › tiles'),
    h('p', { class: 'lede' },
      'One monochrome 8 × 10 tile per printable ASCII character. Only the characters the string uses are exported.'),
    h('div', { class: 'tiles-layout' },
      grid.el,
      h('div', { class: 'tile-editor' },
        title, usage, canvas, tools,
        h('p', {}, h('span', { class: 'muted' }, 'Rows: '), rowsText),
        h('label', { class: 'check' }, tall, ' Tall pixels (as on the microbee)'),
        h('p', { class: 'hint' },
          'Drag to draw, right-drag (or Ctrl-drag) to erase. Type a character to pick its tile; arrows move around the grid.'))),
    h('section', {}, h('h2', {}, 'Preview'), preview.el),
  );
  select(code);

  return {
    update(next) {
      if (next.code != null && next.code !== code) select(next.code);
    },
    unmount() {
      document.removeEventListener('keydown', onKey);
      offs.forEach(off => off());
      grid.dispose();
      preview.dispose();
    },
  };
}
