// The font's string. It can only hold printable ASCII, so typing or pasting tidies the text:
// line breaks and tabs become spaces, typographic punctuation becomes its ASCII equivalent, and
// anything else is left out (with a note saying what).
import { on } from '../bus.js';
import { h } from '../dom.js';
import { setText, state } from '../state.js';
import { textPreview } from '../text-preview.js';
import { fontStats } from './font-overview.js';

const REPLACEMENTS = {
  '‘': "'", '’': "'", '‚': "'", '‛': "'", '′': "'",
  '“': '"', '”': '"', '„': '"', '″': '"',
  '‐': '-', '‑': '-', '‒': '-', '–': '-', '—': '-', '−': '-',
  '…': '...', ' ': ' ', '×': 'x',
};

function clean(raw) {
  const { firstCode, lastCode, maxTextLength } = state.font;
  const dropped = new Set();
  let text = '';
  for (const character of raw.replace(/\r\n|[\r\n\t]/g, ' ')) {
    for (const replacement of REPLACEMENTS[character] ?? character) {
      const code = replacement.charCodeAt(0);
      if (replacement.length === 1 && code >= firstCode && code <= lastCode) text += replacement;
      else dropped.add(character);
    }
  }
  return { text: text.slice(0, maxTextLength), dropped };
}

export function stringView(el) {
  const input = h('textarea', {
    class: 'string-input',
    rows: 5,
    spellcheck: 'false',
    maxlength: state.font.maxTextLength,
    'aria-label': 'String',
  });
  input.value = state.font.text;
  const stats = h('p', { class: 'muted' });
  const note = h('p', { class: 'note', hidden: true });
  const preview = textPreview();

  function showStats() {
    stats.textContent = `${fontStats()} (at most ${state.font.maxTextLength.toLocaleString()} characters)`;
  }

  input.addEventListener('input', () => {
    const { text, dropped } = clean(input.value);
    if (text !== input.value) {
      const caret = clean(input.value.slice(0, input.selectionStart)).text.length;
      input.value = text;
      input.setSelectionRange(caret, caret);
    }
    note.hidden = dropped.size === 0;
    note.textContent = dropped.size === 0 ? ''
      : `Left out (the string only holds printable ASCII): ${[...dropped].map(c => JSON.stringify(c)).join(' ')}`;
    setText(text);
  });

  const off = on('text', () => {
    if (input.value !== state.font.text) input.value = state.font.text;
    showStats();
  });
  showStats();

  el.replaceChildren(
    h('h1', {}, 'wavetext_font › string'),
    h('p', { class: 'lede' },
      'The message the wave text effect scrolls. The preview spaces the characters out the way the effect draws them; ',
      'the string itself has no extra spaces.'),
    input, note, stats,
    h('section', {}, h('h2', {}, 'Preview'), preview.el),
  );
  input.focus();

  return {
    unmount() {
      off();
      preview.dispose();
    },
  };
}
