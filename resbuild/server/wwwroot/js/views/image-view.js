// One evlores image: its variable name, its size, and its pixels.
import { on } from '../bus.js';
import { h, isTyping } from '../dom.js';
import { imageBuffer, rgb, sizeCanvas } from '../render.js';
import { deleteImage, imageById, imageBytes, imageChanged, imageHistory, nameProblem, renameImage, state } from '../state.js';
import { clamp, line, perFrame } from '../util.js';

const ZOOMS = ['fit', 1, 2, 3, 4, 6, 8, 12, 16, 24];
const TOOLS = [
  { id: 'pencil', label: 'Pencil', key: 'b' },
  { id: 'fill', label: 'Fill', key: 'f' },
  { id: 'pick', label: 'Pick', key: 'i' },
];

// Shift+arrow key: the step every pixel moves, and how the button shows it.
const SHIFTS = { ArrowLeft: [-1, 0], ArrowRight: [1, 0], ArrowUp: [0, -1], ArrowDown: [0, 1] };
const SHIFT_LABELS = {
  ArrowLeft: ['←', 'left'], ArrowRight: ['→', 'right'], ArrowUp: ['↑', 'up'], ArrowDown: ['↓', 'down'],
};

// Carried from image to image.
const colours = { left: 15, right: 0 };
let tool = 'pencil';
let zoomChoice = 'fit';
let showGrid = true;

export function imageView(el, { id }) {
  const image = imageById(id);
  if (!image) {
    el.replaceChildren(
      h('h1', {}, 'No such image'),
      h('p', {}, 'It may have been deleted. ', h('a', { href: '#/evlores_image' }, 'See all the images.')));
    return {};
  }

  const { heightStep, maxWidth, maxHeight } = state.evlores;
  const history = imageHistory(image.id);
  let stroke = null;

  // --------------------------------------------------------- controls

  const nameInput = h('input', {
    class: 'name-input', spellcheck: 'false', autocomplete: 'off', maxlength: state.names.maxLength, 'aria-label': 'Variable name',
  });
  nameInput.value = image.name;
  const nameNote = h('span', { class: 'field-problem' });

  const widthInput = h('input', { type: 'number', min: 1, max: maxWidth, 'aria-label': 'Width' });
  const heightInput = h('input', { type: 'number', min: heightStep, max: maxHeight, step: heightStep, 'aria-label': 'Height' });
  const sizeNote = h('span', { class: 'muted' });

  const swatches = state.palette.map((_, index) => h('button', {
    class: 'swatch',
    style: `background: ${rgb(index)}`,
    title: `${index}: ${state.palette[index].join(', ')}`,
    onclick: () => setColour('left', index),
    oncontextmenu: event => {
      event.preventDefault();
      setColour('right', index);
    },
  }));
  const leftChip = h('span', { class: 'chip' });
  const rightChip = h('span', { class: 'chip' });

  const toolButtons = TOOLS.map(entry => h('button', {
    class: 'tool', title: `${entry.label} (${entry.key.toUpperCase()})`, onclick: () => setTool(entry.id),
  }, entry.label));

  const zoomSelect = h('select', { 'aria-label': 'Zoom', onchange: () => { zoomChoice = zoomSelect.value === 'fit' ? 'fit' : Number(zoomSelect.value); draw(); } },
    ZOOMS.map(zoom => h('option', { value: zoom, selected: zoom === zoomChoice }, zoom === 'fit' ? 'Fit' : `${zoom}×`)));
  const gridToggle = h('input', { type: 'checkbox', checked: showGrid, onchange: () => { showGrid = gridToggle.checked; draw(); } });

  const canvas = h('canvas', { class: 'pixels image-canvas' });
  const wrap = h('div', { class: 'canvas-wrap' }, canvas);
  const status = h('span', { class: 'muted' });

  // ---------------------------------------------------------- drawing

  function zoom() {
    if (zoomChoice !== 'fit') return zoomChoice;
    const width = wrap.clientWidth || 800;
    const height = Math.max(200, window.innerHeight - wrap.getBoundingClientRect().top - 48);
    return clamp(Math.floor(Math.min(width / image.width, height / (image.height * 2))), 1, 32);
  }

  const draw = perFrame(() => {
    const scale = zoom();
    const width = image.width * scale;
    const height = image.height * 2 * scale;
    const context = sizeCanvas(canvas, width, height);
    imageBuffer(image).drawTo(context, 0, 0, width, height);

    if (showGrid && scale >= 4) {
      for (let x = 1; x < image.width; x++) {
        context.fillStyle = x % 8 === 0 ? 'rgba(128, 160, 255, 0.55)' : 'rgba(128, 160, 255, 0.18)';
        context.fillRect(x * scale, 0, 1, height);
      }
      for (let y = 1; y < image.height; y++) {
        context.fillStyle = y % 8 === 0 ? 'rgba(128, 160, 255, 0.55)' : 'rgba(128, 160, 255, 0.18)';
        context.fillRect(0, y * scale * 2, width, 1);
      }
    }
    zoomSelect.options[0].textContent = zoomChoice === 'fit' ? `Fit (${scale}×)` : 'Fit';
  });

  function showSize() {
    widthInput.value = image.width;
    heightInput.value = image.height;
    sizeNote.textContent = `${imageBytes(image).toLocaleString()} bytes exported`;
  }

  function showColours() {
    leftChip.style.background = rgb(colours.left);
    leftChip.title = `Left button: colour ${colours.left}`;
    rightChip.style.background = rgb(colours.right);
    rightChip.title = `Right button: colour ${colours.right}`;
    swatches.forEach((swatch, index) => {
      swatch.classList.toggle('left', index === colours.left);
      swatch.classList.toggle('right', index === colours.right);
    });
  }

  function setColour(which, index) {
    colours[which] = index;
    showColours();
  }

  function setTool(next) {
    tool = next;
    toolButtons.forEach((button, index) => button.classList.toggle('active', TOOLS[index].id === tool));
    canvas.dataset.tool = tool;
  }

  // ---------------------------------------------------------- editing

  const snapshot = () => ({ width: image.width, height: image.height, pixels: image.pixels.slice() });

  function restore(saved) {
    if (!saved) return;
    image.width = saved.width;
    image.height = saved.height;
    image.pixels = saved.pixels;
    imageChanged(image);
  }

  function undo() { restore(history.undo(snapshot)); }
  function redo() { restore(history.redo(snapshot)); }

  function pixelAt(event) {
    const box = canvas.getBoundingClientRect();
    return {
      x: Math.floor(((event.clientX - box.left) / box.width) * image.width),
      y: Math.floor(((event.clientY - box.top) / box.height) * image.height),
    };
  }

  const inside = ({ x, y }) => x >= 0 && y >= 0 && x < image.width && y < image.height;

  function paint(to) {
    const from = stroke.last ?? to;
    let changed = false;
    for (const [x, y] of line(from.x, from.y, to.x, to.y)) {
      if (!inside({ x, y })) continue;
      const i = y * image.width + x;
      if (image.pixels[i] === stroke.colour) continue;
      if (!stroke.recorded) {
        history.record(snapshot());
        stroke.recorded = true;
      }
      image.pixels[i] = stroke.colour;
      changed = true;
    }
    stroke.last = to;
    if (changed) imageChanged(image);
  }

  /** Flood fills the area of one colour around (x, y). */
  function fill({ x, y }, colour) {
    const { width, height, pixels } = image;
    const target = pixels[y * width + x];
    if (target === colour) return;
    history.record(snapshot());
    const stack = [y * width + x];
    while (stack.length > 0) {
      const i = stack.pop();
      if (pixels[i] !== target) continue;
      pixels[i] = colour;
      const px = i % width;
      if (px > 0) stack.push(i - 1);
      if (px < width - 1) stack.push(i + 1);
      if (i >= width) stack.push(i - width);
      if (i < width * (height - 1)) stack.push(i + width);
    }
    imageChanged(image);
  }

  /** Crops or grows the image, keeping its top-left corner; new pixels are colour 0. */
  function resize() {
    const width = clamp(Math.round(Number(widthInput.value)) || image.width, 1, maxWidth);
    const rawHeight = Math.round(Number(heightInput.value)) || image.height;
    const height = clamp(Math.ceil(rawHeight / heightStep) * heightStep, heightStep, maxHeight);
    if (width === image.width && height === image.height) {
      showSize();
      return;
    }
    history.record(snapshot());
    const pixels = new Uint8Array(width * height);
    for (let y = 0; y < Math.min(height, image.height); y++) {
      for (let x = 0; x < Math.min(width, image.width); x++) pixels[y * width + x] = image.pixels[y * image.width + x];
    }
    image.width = width;
    image.height = height;
    image.pixels = pixels;
    imageChanged(image);
  }

  /** Moves every pixel one step, wrapping round to the other side, as one undo step. */
  function shift(dx, dy) {
    const { width, height, pixels } = image;
    if (dx !== 0 && width === 1) return;
    const shifted = new Uint8Array(pixels.length);
    for (let y = 0; y < height; y++) {
      const to = ((y + dy + height) % height) * width;
      for (let x = 0; x < width; x++) shifted[to + (x + dx + width) % width] = pixels[y * width + x];
    }
    history.record(snapshot());
    image.pixels = shifted;
    imageChanged(image);
  }

  function showStatus(event) {
    const point = pixelAt(event);
    status.textContent = inside(point)
      ? `x ${point.x}, y ${point.y}: colour ${image.pixels[point.y * image.width + point.x]}`
      : '';
  }

  canvas.addEventListener('pointerdown', event => {
    if (event.button !== 0 && event.button !== 2) return;
    event.preventDefault();
    const which = event.button === 2 ? 'right' : 'left';
    const point = pixelAt(event);
    if (!inside(point)) return;
    if (tool === 'pick' || event.altKey) {
      setColour(which, image.pixels[point.y * image.width + point.x]);
    } else if (tool === 'fill') {
      fill(point, colours[which]);
    } else {
      canvas.setPointerCapture(event.pointerId);
      stroke = { colour: colours[which], last: null, recorded: false };
      paint(point);
    }
  });
  canvas.addEventListener('pointermove', event => {
    showStatus(event);
    if (stroke) paint(pixelAt(event));
  });
  const endStroke = () => { stroke = null; };
  canvas.addEventListener('pointerup', endStroke);
  canvas.addEventListener('pointercancel', endStroke);
  canvas.addEventListener('pointerleave', () => { status.textContent = ''; });
  canvas.addEventListener('contextmenu', event => event.preventDefault());

  nameInput.addEventListener('input', () => {
    const name = nameInput.value.trim();
    const problem = nameProblem(name, image.id);
    nameInput.classList.toggle('invalid', problem !== null);
    nameNote.textContent = problem ?? '';
    if (problem === null) renameImage(image, name);
  });
  nameInput.addEventListener('blur', () => {
    // A name that cannot be used was never saved: put the saved one back.
    nameInput.value = image.name;
    nameInput.classList.remove('invalid');
    nameNote.textContent = '';
  });
  nameInput.addEventListener('keydown', event => { if (event.key === 'Enter') nameInput.blur(); });
  widthInput.addEventListener('change', resize);
  heightInput.addEventListener('change', resize);

  async function remove() {
    if (!confirm(`Delete ${image.name}? This cannot be undone.`)) return;
    try {
      await deleteImage(image);
      location.hash = '#/evlores_image';
    } catch (error) {
      alert(`Could not delete ${image.name}: ${error.message}`);
    }
  }

  function onKey(event) {
    if (isTyping(event)) return;
    const ctrl = event.ctrlKey || event.metaKey;
    const key = event.key.toLowerCase();
    let handled = true;
    if (ctrl && key === 'z') event.shiftKey ? redo() : undo();
    else if (ctrl && key === 'y') redo();
    else if (ctrl || event.altKey) handled = false;
    else if (event.shiftKey && SHIFTS[event.key]) shift(...SHIFTS[event.key]);
    else if (key === 'x') {
      [colours.left, colours.right] = [colours.right, colours.left];
      showColours();
    } else if (TOOLS.some(entry => entry.key === key)) setTool(TOOLS.find(entry => entry.key === key).id);
    else handled = false;
    if (handled) event.preventDefault();
  }
  document.addEventListener('keydown', onKey);

  const offs = [
    on('image', changed => {
      if (changed !== image.id) return;
      showSize();
      draw();
    }),
    on('images', () => {
      if (!imageById(image.id)) return;
      if (document.activeElement !== nameInput) nameInput.value = image.name;
    }),
  ];
  window.addEventListener('resize', draw);

  el.replaceChildren(
    h('div', { class: 'image-head' },
      h('label', { class: 'field' }, h('span', {}, 'Variable name'), nameInput),
      h('label', { class: 'field small' }, h('span', {}, 'Width'), widthInput),
      h('label', { class: 'field small' }, h('span', {}, 'Height'), heightInput),
      sizeNote,
      h('button', { class: 'danger', onclick: remove }, 'Delete image')),
    nameNote,
    h('div', { class: 'image-tools' },
      h('div', { class: 'palette' }, swatches),
      h('button', {
        class: 'chips', title: 'Swap (X)',
        onclick: () => { [colours.left, colours.right] = [colours.right, colours.left]; showColours(); },
      }, leftChip, rightChip),
      h('div', { class: 'toolbar' }, toolButtons),
      h('div', { class: 'toolbar' },
        h('button', { onclick: undo, title: 'Ctrl+Z' }, 'Undo'),
        h('button', { onclick: redo, title: 'Ctrl+Y' }, 'Redo')),
      h('div', { class: 'toolbar', role: 'group', 'aria-label': 'Shift the pixels' },
        h('span', { class: 'muted' }, 'Shift'),
        Object.entries(SHIFTS).map(([key, [dx, dy]]) => h('button', {
          onclick: () => shift(dx, dy),
          title: `Shift every pixel ${SHIFT_LABELS[key][1]}, wrapping round (Shift+${SHIFT_LABELS[key][0]})`,
          'aria-label': `Shift ${SHIFT_LABELS[key][1]}`,
        }, SHIFT_LABELS[key][0]))),
      h('label', { class: 'check' }, 'Zoom ', zoomSelect),
      h('label', { class: 'check' }, gridToggle, ' Grid')),
    wrap,
    h('p', { class: 'hint' }, status, ' ',
      'Left and right buttons paint with the left and right colours (click or right-click a swatch to choose them). ',
      'Alt-click picks a colour. B, F, I pick the tool; X swaps the colours; Shift+arrows shift the pixels.'),
  );
  showSize();
  showColours();
  setTool(tool);
  draw();

  return {
    unmount() {
      document.removeEventListener('keydown', onKey);
      window.removeEventListener('resize', draw);
      offs.forEach(off => off());
    },
  };
}
