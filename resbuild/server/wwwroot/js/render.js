// Drawing. Everything is drawn as an image at its own resolution (one canvas pixel per asset
// pixel) and then scaled up with smoothing off, so pixels stay crisp at any zoom and screen DPI.
import { state } from './state.js';

const scratch = document.createElement('canvas');
const scratchContext = scratch.getContext('2d');

export const INK = 7;   // palette white: lit font pixels
export const PAPER = 0; // palette black
/** Washes the cell of a character the string uses that has no tile yet. */
export const MISSING = [110, 28, 28, 255];

/** The palette colour as CSS. */
export function rgb(index) {
  const [r, g, b] = state.palette[index];
  return `rgb(${r}, ${g}, ${b})`;
}

export function rgba(index) {
  return [...state.palette[index], 255];
}

/** Sizes a canvas in CSS pixels, backed at the screen's resolution. */
export function sizeCanvas(canvas, width, height) {
  const ratio = window.devicePixelRatio || 1;
  canvas.style.width = `${width}px`;
  canvas.style.height = `${height}px`;
  canvas.width = Math.max(1, Math.round(width * ratio));
  canvas.height = Math.max(1, Math.round(height * ratio));
  const context = canvas.getContext('2d');
  context.setTransform(ratio, 0, 0, ratio, 0, 0);
  context.imageSmoothingEnabled = false;
  return context;
}

/** A width x height RGBA buffer to draw into, and the call that puts it on a canvas. */
export function pixelBuffer(width, height) {
  const data = new Uint8ClampedArray(width * height * 4);
  return {
    width,
    height,
    data,
    set(x, y, [r, g, b, a]) {
      const i = (y * width + x) * 4;
      data[i] = r;
      data[i + 1] = g;
      data[i + 2] = b;
      data[i + 3] = a;
    },
    fill(colour) {
      for (let i = 0; i < width * height; i++) data.set(colour, i * 4);
    },
    /** Draws the buffer scaled into the rectangle (CSS pixels). */
    drawTo(context, x, y, drawWidth, drawHeight) {
      scratch.width = width;
      scratch.height = height;
      scratchContext.putImageData(new ImageData(data, width, height), 0, 0);
      context.imageSmoothingEnabled = false;
      context.drawImage(scratch, 0, 0, width, height, x, y, drawWidth, drawHeight);
    },
  };
}

/** Puts a tile's rows into the buffer at (left, top). */
export function putTile(buffer, rows, left = 0, top = 0, ink = rgba(INK), paper = rgba(PAPER)) {
  const { tileWidth } = state.font;
  rows.forEach((row, y) => {
    for (let x = 0; x < tileWidth; x++) {
      buffer.set(left + x, top + y, row & (0x80 >> x) ? ink : paper);
    }
  });
}

/** Draws one tile filling the canvas's CSS size. */
export function drawTile(canvas, rows, width, height) {
  const { tileWidth, tileHeight } = state.font;
  const context = sizeCanvas(canvas, width, height);
  const buffer = pixelBuffer(tileWidth, tileHeight);
  putTile(buffer, rows);
  buffer.drawTo(context, 0, 0, width, height);
}

/** An evlores image's pixels as an RGBA buffer, one buffer pixel per image pixel. */
export function imageBuffer(image) {
  const buffer = pixelBuffer(image.width, image.height);
  const colours = state.palette.map((_, index) => rgba(index));
  for (let i = 0; i < image.pixels.length; i++) buffer.data.set(colours[image.pixels[i]], i * 4);
  return buffer;
}

/** A thumbnail: the image (pixels twice as high as wide) fitted inside width x height. */
export function drawThumbnail(canvas, image, width, height) {
  const context = sizeCanvas(canvas, width, height);
  context.fillStyle = '#000';
  context.fillRect(0, 0, width, height);
  const scale = Math.min(width / image.width, height / (image.height * 2));
  const drawWidth = image.width * scale;
  const drawHeight = image.height * 2 * scale;
  imageBuffer(image).drawTo(context, (width - drawWidth) / 2, (height - drawHeight) / 2, drawWidth, drawHeight);
}

