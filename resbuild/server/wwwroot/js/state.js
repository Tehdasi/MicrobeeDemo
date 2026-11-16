// The client's copy of every asset. Views edit it through the functions here, which tell the
// other views (bus events below) and queue the save.
//
// Events: 'text' (the font's string changed), 'tile' (code), 'images' (an image was added,
// removed or renamed), 'image' (id: its pixels or size changed).
import { api, isRetryable } from './api.js';
import { emit } from './bus.js';
import { History } from './history.js';
import * as saver from './saver.js';

const HEX = '0123456789abcdef';

export const state = {
  palette: [],   // [[r, g, b], ...] - the microbee palette
  font: null,    // { firstCode, lastCode, tileWidth, tileHeight, bitmapBytes, maxTextLength, text, tiles: Map<code, rows[]> }
  evlores: null, // { heightStep, maxWidth, maxHeight }
  images: [],    // [{ id, name, width, height, pixels: Uint8Array }]
  names: null,   // { maxLength, reserved: Set }
};

export async function load() {
  const loaded = await api.state();
  state.palette = loaded.palette;
  state.font = {
    ...loaded.font,
    tiles: new Map(Object.entries(loaded.font.tiles).map(([code, rows]) => [Number(code), rows])),
  };
  state.evlores = loaded.evlores;
  state.images = loaded.images.map(fromJson);
  state.names = { maxLength: loaded.names.maxLength, reserved: new Set(loaded.names.reserved) };
}

// ---------------------------------------------------------------- font

export const fontHistory = new History();

export function blankRows() {
  return new Array(state.font.tileHeight).fill(0);
}

/** A copy of the tile's rows (all zero for a tile not drawn yet). */
export function tileRows(code) {
  return state.font.tiles.get(code)?.slice() ?? blankRows();
}

export function hasTile(code) {
  return state.font.tiles.has(code);
}

export function setText(text) {
  if (text === state.font.text) return;
  state.font.text = text;
  emit('text');
  saver.schedule('text', () => api.setText(state.font.text));
}

const dirtyTiles = new Set();

export function setTile(code, rows) {
  if (rows.every(row => row === 0)) state.font.tiles.delete(code);
  else state.font.tiles.set(code, rows.slice());
  dirtyTiles.add(code);
  emit('tile', code);
  saver.schedule('tiles', saveTiles);
}

async function saveTiles() {
  const codes = [...dirtyTiles];
  dirtyTiles.clear();
  try {
    await api.setTiles(Object.fromEntries(codes.map(code => [code, tileRows(code)])));
  } catch (error) {
    // Kept for the retry; a refused batch is dropped with the rest of the job.
    if (isRetryable(error)) codes.forEach(code => dirtyTiles.add(code));
    throw error;
  }
}

// -------------------------------------------------------------- images

const imageHistories = new Map();

function fromJson(json) {
  return {
    id: json.id,
    name: json.name,
    width: json.width,
    height: json.height,
    pixels: Uint8Array.from(json.pixels, digit => HEX.indexOf(digit.toLowerCase())),
  };
}

export function imageById(id) {
  return state.images.find(image => image.id === id) ?? null;
}

export function imageHistory(id) {
  if (!imageHistories.has(id)) imageHistories.set(id, new History());
  return imageHistories.get(id);
}

export async function createImage() {
  const image = fromJson(await api.createImage());
  state.images.push(image);
  emit('images');
  return image;
}

/** Call after changing an image's pixels or size in place. */
export function imageChanged(image) {
  emit('image', image.id);
  saver.schedule(`pixels:${image.id}`, () => savePixels(image.id));
}

async function savePixels(id) {
  const image = imageById(id);
  if (!image) return;
  const pixels = Array.from(image.pixels, value => HEX[value]).join('');
  try {
    await api.setPixels(id, image.width, image.height, pixels);
  } catch (error) {
    // Deleted while the save was on its way.
    if (error.status === 404 && !imageById(id)) return;
    throw error;
  }
}

/** Only for names nameProblem() accepts. */
export function renameImage(image, name) {
  if (name === image.name) return;
  image.name = name;
  emit('images');
  saver.schedule(`name:${image.id}`, async () => {
    const current = imageById(image.id);
    if (current) await api.renameImage(current.id, current.name);
  });
}

export async function deleteImage(image) {
  saver.cancel(`pixels:${image.id}`);
  saver.cancel(`name:${image.id}`);
  await api.deleteImage(image.id);
  state.images = state.images.filter(other => other !== image);
  imageHistories.delete(image.id);
  emit('images');
}

/** The size of an image's exported array: two pixels (one above the other) per byte. */
export function imageBytes(image) {
  return (image.width * image.height) / 2;
}

/** Everything an image's export declares: the array and its size macros. */
export function imageSymbols(name) {
  const upper = name.toUpperCase();
  return [name, `${upper}_WIDTH`, `${upper}_HEIGHT`];
}

/** Why the image cannot be called this (the server's rules), or null when it can. */
export function nameProblem(name, imageId) {
  const { maxLength, reserved } = state.names;
  if (name.length === 0) return 'The variable name cannot be empty.';
  if (name.length > maxLength) return `The variable name can be at most ${maxLength} characters.`;
  if (!/^[A-Za-z_][A-Za-z0-9_]*$/.test(name)) return 'Use letters, digits and _, not starting with a digit.';
  if (/^(__|_[A-Z])/.test(name)) return 'Names starting with __, or _ and a capital, are reserved in C.';

  const others = state.images.filter(image => image.id !== imageId).map(image => image.name);
  const twin = others.find(other => other.toLowerCase() === name.toLowerCase());
  if (twin) return `Another image is already called ${twin}.`;

  if (reserved.has(name)) return `${name} is a C keyword or a name the demo already uses.`;
  const taken = new Set([...reserved, ...others.flatMap(imageSymbols)]);
  const clash = imageSymbols(name).find(symbol => taken.has(symbol));
  return clash ? `${name} would also declare ${clash}, which is already taken.` : null;
}
