// The sidebar: asset types, and under each the data it is built from (for evlores images, the
// images themselves, with thumbnails).
import { on } from './bus.js';
import { h } from './dom.js';
import { drawThumbnail } from './render.js';
import { createImage, imageById, state } from './state.js';

const THUMB_WIDTH = 40;
const THUMB_HEIGHT = 20;

export function mountTree(el, currentRoute) {
  const thumbnails = new Map();
  const staleThumbnails = new Set();
  let frame = 0;

  function render() {
    const route = currentRoute();
    const at = (type, item = '') => route.type === type && route.item === item;
    thumbnails.clear();

    el.replaceChildren(h('ul', { class: 'tree-root' },
      typeNode('wavetext_font', '#/wavetext_font', at('wavetext_font'), [
        leaf('string', '#/wavetext_font/string', at('wavetext_font', 'string')),
        leaf('tiles', '#/wavetext_font/tiles', at('wavetext_font', 'tiles')),
      ]),
      typeNode('evlores image', '#/evlores_image', at('evlores_image'), [
        ...state.images.map(image => {
          const canvas = h('canvas', { class: 'pixels thumb' });
          thumbnails.set(image.id, canvas);
          drawThumbnail(canvas, image, THUMB_WIDTH, THUMB_HEIGHT);
          return leaf(image.name, `#/evlores_image/${image.id}`, at('evlores_image', String(image.id)), canvas);
        }),
        h('li', {}, h('button', { class: 'tree-add', onclick: addImage }, '+ New image')),
      ]),
    ));
  }

  function redrawThumbnails() {
    frame = 0;
    for (const id of staleThumbnails) {
      const image = imageById(id);
      const canvas = thumbnails.get(id);
      if (image && canvas) drawThumbnail(canvas, image, THUMB_WIDTH, THUMB_HEIGHT);
    }
    staleThumbnails.clear();
  }

  on('images', render);
  on('image', id => {
    staleThumbnails.add(id);
    frame ||= requestAnimationFrame(redrawThumbnails);
  });

  return { render };
}

function typeNode(label, href, active, children) {
  return h('li', { class: 'tree-type' },
    h('a', { class: `tree-link type${active ? ' active' : ''}`, href }, label),
    h('ul', {}, children));
}

function leaf(label, href, active, icon) {
  return h('li', {}, h('a', { class: `tree-link leaf${active ? ' active' : ''}`, href }, icon, h('span', {}, label)));
}

export async function addImage() {
  try {
    const image = await createImage();
    location.hash = `#/evlores_image/${image.id}`;
  } catch (error) {
    alert(`Could not add an image: ${error.message}`);
  }
}
