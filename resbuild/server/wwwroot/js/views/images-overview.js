// The evlores images at a glance.
import { on } from '../bus.js';
import { h } from '../dom.js';
import { exportPanel } from '../export-panel.js';
import { drawThumbnail } from '../render.js';
import { imageById, imageBytes, state } from '../state.js';
import { addImage } from '../tree.js';

const THUMB_WIDTH = 192;
const THUMB_HEIGHT = 96;

export function imagesOverview(el) {
  const cards = h('div', { class: 'image-cards' });
  const canvases = new Map();
  const exports = exportPanel();

  function render() {
    canvases.clear();
    cards.replaceChildren(
      ...state.images.map(image => {
        const canvas = h('canvas', { class: 'pixels' });
        canvases.set(image.id, canvas);
        drawThumbnail(canvas, image, THUMB_WIDTH, THUMB_HEIGHT);
        return h('a', { class: 'image-card', href: `#/evlores_image/${image.id}` },
          canvas,
          h('span', { class: 'image-card-name' }, image.name),
          h('span', { class: 'muted' }, `${image.width} × ${image.height}, ${imageBytes(image).toLocaleString()} bytes`));
      }),
      h('button', { class: 'image-card add', onclick: addImage }, '+ New image'),
    );
  }

  const offs = [
    on('images', render),
    on('image', id => {
      const image = imageById(id);
      if (image && canvases.has(id)) drawThumbnail(canvases.get(id), image, THUMB_WIDTH, THUMB_HEIGHT);
    }),
  ];
  render();

  el.replaceChildren(
    h('h1', {}, 'evlores image'),
    h('p', { class: 'lede' },
      'Images made of pixels twice as high as wide, each pixel any of the 16 microbee colours. ',
      'Each image is exported under its own variable name, two pixels (one above the other) to a byte.'),
    cards,
    h('section', {}, h('h2', {}, 'Export'), exports.el),
  );

  return {
    unmount() {
      offs.forEach(off => off());
      exports.dispose();
    },
  };
}
