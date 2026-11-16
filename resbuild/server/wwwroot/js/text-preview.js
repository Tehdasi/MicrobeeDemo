// The font's string drawn in its tiles, spaced out the way the wave text effect shows it: each character is
// followed by a blank character cell. Lines wrap at the screen's 64 columns, so 32 characters to
// a line. Characters the string uses that have no tile yet are washed red and listed below.
import { on } from './bus.js';
import { h } from './dom.js';
import { MISSING, pixelBuffer, putTile, rgba, PAPER, sizeCanvas } from './render.js';
import { hasTile, state, tileRows } from './state.js';
import { charLabel, clamp, perFrame, tileAspect } from './util.js';

const SCREEN_COLUMNS = 64;
const SPACING = 1; // blank cells after each character
const PER_LINE = SCREEN_COLUMNS / (1 + SPACING);
const LINE_GAP = 2; // blank pixel rows between lines

/** Characters the string uses that have no tile yet (space is meant to be blank). */
export function undrawnCodes() {
  const codes = new Set(Array.from(state.font.text, character => character.charCodeAt(0)));
  return [...codes].filter(code => code !== 32 && !hasTile(code)).sort((a, b) => a - b);
}

export function textPreview() {
  const canvas = h('canvas', { class: 'pixels text-preview-canvas' });
  const missing = h('p', { class: 'missing' });
  const el = h('div', { class: 'text-preview' }, canvas, missing);

  const draw = perFrame(() => {
    const { tileWidth, tileHeight } = state.font;
    const text = state.font.text;
    const lines = Math.max(1, Math.ceil(text.length / PER_LINE));
    const cell = tileWidth * (1 + SPACING);
    const buffer = pixelBuffer(SCREEN_COLUMNS * tileWidth, lines * tileHeight + (lines - 1) * LINE_GAP);
    buffer.fill(rgba(PAPER));

    for (let i = 0; i < text.length; i++) {
      const code = text.charCodeAt(i);
      const left = (i % PER_LINE) * cell;
      const top = Math.floor(i / PER_LINE) * (tileHeight + LINE_GAP);
      if (hasTile(code)) {
        putTile(buffer, tileRows(code), left, top);
      } else if (code !== 32) {
        for (let y = 0; y < tileHeight; y++) for (let x = 0; x < tileWidth; x++) buffer.set(left + x, top + y, MISSING);
      }
    }

    const available = el.clientWidth || buffer.width;
    const scale = clamp(Math.floor(available / buffer.width), 1, 3);
    const width = buffer.width * scale;
    const height = buffer.height * scale * tileAspect();
    buffer.drawTo(sizeCanvas(canvas, width, height), 0, 0, width, height);

    const undrawn = undrawnCodes();
    missing.replaceChildren(...(undrawn.length === 0 ? [] : [
      'No tile yet: ',
      ...undrawn.map(code => h('a', { class: 'char-link', href: `#/wavetext_font/tiles/${code}` }, charLabel(code))),
    ]));
  });

  const offs = [on('text', draw), on('tile', draw), on('settings', draw)];
  window.addEventListener('resize', draw);
  draw();

  return {
    el,
    dispose() {
      offs.forEach(off => off());
      window.removeEventListener('resize', draw);
    },
  };
}
