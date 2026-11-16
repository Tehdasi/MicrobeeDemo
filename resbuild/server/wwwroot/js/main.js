// Boots the page: loads every asset, then routes #/<asset type>/<data or image>/... to a view.
import { on } from './bus.js';
import { h } from './dom.js';
import * as saver from './saver.js';
import { imageById, load } from './state.js';
import { mountTree } from './tree.js';
import { fontOverview } from './views/font-overview.js';
import { imageView } from './views/image-view.js';
import { imagesOverview } from './views/images-overview.js';
import { stringView } from './views/string-view.js';
import { tilesView } from './views/tiles-view.js';

const viewEl = document.getElementById('view');
const crumbsEl = document.getElementById('crumbs');
const statusEl = document.getElementById('save-status');

let current = null; // { key, view }
let tree = null;

function currentRoute() {
  const [type = '', item = '', detail = ''] = location.hash.replace(/^#\/?/, '').split('/').map(decodeURIComponent);
  return { type, item, detail };
}

/** The view for a route, or null when the route is not one. */
function resolve({ type, item, detail }) {
  if (type === 'wavetext_font') {
    if (!item) return { key: 'font', mount: fontOverview };
    if (item === 'string') return { key: 'string', mount: stringView };
    if (item === 'tiles') return { key: 'tiles', mount: tilesView, params: { code: detail ? Number(detail) : null } };
  }
  if (type === 'evlores_image') {
    if (!item) return { key: 'images', mount: imagesOverview };
    return { key: `image:${item}`, mount: imageView, params: { id: Number(item) } };
  }
  return null;
}

function show() {
  const route = currentRoute();
  const target = resolve(route);
  if (!target) {
    location.replace('#/wavetext_font');
    return;
  }

  if (current?.key === target.key && current.view.update) {
    current.view.update(target.params ?? {});
  } else {
    current?.view.unmount?.();
    viewEl.replaceChildren();
    viewEl.scrollTop = 0;
    current = { key: target.key, view: target.mount(viewEl, target.params ?? {}) ?? {} };
  }
  tree.render();
  showCrumbs();
}

function showCrumbs() {
  const { type, item } = currentRoute();
  const typeLabel = type === 'evlores_image' ? 'evlores image' : type;
  const itemLabel = type === 'evlores_image' && item ? imageById(Number(item))?.name ?? '?' : item;
  crumbsEl.replaceChildren(
    h('a', { href: `#/${type}` }, typeLabel),
    itemLabel ? ` › ${itemLabel}` : '');
  document.title = `${itemLabel || typeLabel} - Resbuild`;
}

const SAVE_TEXT = {
  saved: () => 'All changes saved',
  pending: () => 'Unsaved changes…',
  saving: () => 'Saving…',
  offline: ({ message }) => `Not saved: ${message} Retrying…`,
  error: ({ message }) => `Save refused: ${message}`,
};

on('save', status => {
  statusEl.className = `save-status ${status.state}`;
  statusEl.textContent = SAVE_TEXT[status.state](status);
});
on('images', showCrumbs);

document.addEventListener('keydown', event => {
  if ((event.ctrlKey || event.metaKey) && event.key.toLowerCase() === 's') {
    event.preventDefault();
    saver.flush();
  }
});

try {
  await load();
} catch (error) {
  viewEl.replaceChildren(
    h('h1', {}, 'Cannot load the assets'),
    h('p', { class: 'problem' }, error.message),
    h('p', {}, 'Is the server running? Reload the page once it is.'));
  throw error;
}

tree = mountTree(document.getElementById('tree'), currentRoute);
window.addEventListener('hashchange', show);
show();
statusEl.textContent = SAVE_TEXT.saved();
statusEl.className = 'save-status saved';
