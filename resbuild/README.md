# Resbuild

An editor for the demo's assets, built from `plan.txt`. It is a single page in raw JavaScript (no
framework, no build step) served by a C# server (ASP.NET Core minimal APIs). Asset data lives in
a SQLite database, and every asset is exported as C into `src\res.h` and `src\res.c`. The C files
are rewritten lazily as you edit.

The left sidebar is a tree. Its first level is the asset types; its second level is the data
each type is built from (for evlores images, the images themselves).

## Running it

Double-click `start-resbuild.bat`. It runs the server in that window and opens
<http://localhost:5174> in Firefox (or the default browser) once the server answers. Ctrl+C
stops it, and anything still waiting to be exported is written first.

By hand:

```bash
dotnet run --project server/Resbuild.Server.csproj
```

| What         | Where                         | Setting (`server/appsettings.json`) |
| ------------ | ----------------------------- | ----------------------------------- |
| Database     | `c:\coding\mb2\res\resbuild.db` | `Resbuild:DataDirectory`          |
| C export     | `c:\coding\mb2\src\res.h`, `res.c` | `Resbuild:ExportDirectory`     |

To try something out without touching the demo, point both somewhere else for one run:

```bash
dotnet run --project server/Resbuild.Server.csproj -- --Resbuild:DataDirectory=/tmp/rb --Resbuild:ExportDirectory=/tmp/rb
```

## Asset types

### wavetext_font

The message the wave text effect (`src/wavetext.c`) scrolls, and the font it is drawn in.

- **string**: printable ASCII only (32-126), up to 4096 characters. Typing or pasting tidies it:
  line breaks and tabs become spaces, typographic quotes, dashes and ellipses become ASCII, and
  anything else is left out, with a note saying what.
- **tiles**: one monochrome 8 x 10 tile per printable ASCII character. Pick a character in the
  grid, or just type it. A dot marks characters the string uses. The dot is amber when that
  character has no tile yet.

The preview draws the string in its tiles the way the effect shows it: a blank character cell
after every character, wrapped at the screen's 64 columns. Characters with no tile are washed
red and listed as links to their tile. **Tall pixels** draws tiles twice as high as wide, as on
the microbee, and is remembered in the browser.

| Tile editor           | Does                                    |
| --------------------- | --------------------------------------- |
| drag                  | draws                                   |
| right-drag, Ctrl-drag | erases                                  |
| Shift+arrows          | shifts the tile (wrapping round)        |
| arrows                | moves around the grid                   |
| Delete                | clears the tile                         |
| Ctrl+Z / Ctrl+Y       | undo / redo (a whole drag is one step)  |
| Ctrl+C / Ctrl+V       | copy / paste a tile                     |

### evlores image

Images made of evlores pixels: twice as high as wide, any of the 16 microbee colours, with an even
height. **+ New image** adds a 64 x 32 one (the evlores screen), all colour 0, called `image1`,
`image2` and so on.

- **Variable name**: the C name the image is exported under. It must be a C identifier of up to
  32 characters. It can't be a keyword, a reserved name (`__x`, `_X`), or a name `res.h` already
  uses: another image (ignoring case, since the size macros are upper case), the wavetext_font names,
  or `byte`, `MIN` and the like. A name that can't be used shows in red and isn't saved.
- **Width / Height**: 1-256 wide, 2-256 high in steps of 2. Resizing keeps the top-left corner;
  new pixels are colour 0.

| Image editor          | Does                                                   |
| --------------------- | ------------------------------------------------------ |
| left / right button   | paints (or fills) with the L / R colour                |
| click / right-click a swatch | picks the L / R colour                          |
| Alt-click             | picks the colour under the pointer                     |
| B / F / I             | Pencil / Fill / Pick tool                              |
| X                     | swaps L and R                                          |
| Shift+arrows, or the Shift ← → ↑ ↓ buttons | shifts every pixel one step, wrapping round to the other side |
| Ctrl+Z / Ctrl+Y       | undo / redo, per image (a drag, fill, shift or resize is one step) |

## Saving and export

Nothing needs saving. Edits go to the server a quarter of a second after you stop, and the top
right shows how that stands. Ctrl+S sends them at once. If the server can't be reached, the
page keeps retrying. An edit the server refuses is reported and dropped, so it can't hold up
later edits.

The server writes `res.h` and `res.c` itself, a second after edits stop. A file is only
rewritten when its content changes, so the demo's build only sees real changes. It goes
through a temporary file, so a build never reads half a file. Both files are brought up to
date when the server starts. `build.bat` compiles every `src\*.c`, so `res.c` is part of the
demo with no build changes. The **Export** panel on each asset type's page shows where the files
go, whether they've caught up, and what's in them.

`res.h` includes `misc.h` (for `byte`) and declares:

| Name                    | What it is                                                           |
| ----------------------- | -------------------------------------------------------------------- |
| `wavetext_font_text[]`  | The string, one byte per character: the index of that character's bitmap (so `wavetext_font_bitmaps + wavetext_font_text[i] * 16`). |
| `wavetext_font_bitmaps[]` | A 16-byte bitmap for each different character in the string, in character code order, and none for characters it doesn't use: the tile's 10 rows (bit 7 is the leftmost pixel), then 6 blank rows. |
| `WAVETEXT_FONT_TEXT_LENGTH`, `WAVETEXT_FONT_BITMAP_COUNT`, `WAVETEXT_FONT_BITMAP_BYTES` | Their sizes. |
| `name[]`                | Per image, two pixels per byte, one above the other: the low nibble is the bottom pixel, the high nibble the top one (each a colour, 0-15). Each row of bytes is two rows of pixels, so pixels (x, 2r) and (x, 2r + 1) are `name[r * NAME_WIDTH + x]`, and the array is `NAME_WIDTH * NAME_HEIGHT / 2` bytes. That's the colour byte `evlores.c` gives each character cell, so an image can go straight into colour RAM (as `demo.c` does with `swirl`). In `res.c` each row of bytes is one line. |
| `NAME_WIDTH`, `NAME_HEIGHT` | Per image, its size in pixels.                                   |

Characters the string uses that have no tile yet are exported blank and listed in a comment.
C has no empty arrays, so an empty string exports one placeholder byte and bitmap (the counts
say 0).

## Code

```
start-resbuild.bat        runs the server and opens the page
server/
  Program.cs              startup, settings, the HTTP API
  Microbee.cs             the palette, and the wavetext_font and evlores formats
  AssetStore.cs           the SQLite database
  CNames.cs               what an image's variable name may be
  ResExport.cs            res.h / res.c from the stored assets
  ExportService.cs        lazy, write-if-changed export
  Models.cs               records for the database and the API
  wwwroot/
    index.html, css/app.css
    js/main.js            loading, routing (#/<type>/<data or image id>), save status
    js/state.js           the client's copy of the assets, edits, name rules
    js/saver.js           debounced, retrying save queue
    js/api.js, bus.js, dom.js, history.js, util.js
    js/render.js          crisp pixel drawing
    js/tree.js            the sidebar
    js/char-grid.js       the font's characters as a grid
    js/text-preview.js    the string drawn in its font
    js/export-panel.js    the export's status and content
    js/views/             font-overview, string-view, tiles-view, images-overview, image-view
```

### Database

`resbuild.db`, schema version 3. Older databases are upgraded when the server opens them, so the
resbuild in `c:\coding\mbee` (v1 or v2) can hand its database over: v1 (from before images) gains
the `images` table, and v2 has its `e22_font` rows renamed to `wavetext_font`. After that the old
resbuild refuses to open it.

| Table     | Columns                                                | Notes                                   |
| --------- | ------------------------------------------------------ | --------------------------------------- |
| `meta`    | `key`, `value`                                         | schema version, creation time           |
| `strings` | `asset_type`, `item`, `value`, `updated_at`            | the font's string: (`wavetext_font`, `string`) |
| `tiles`   | `asset_type`, `item`, `code`, `rows`, `updated_at`     | (`wavetext_font`, `tiles`, code); `rows` is 10 bytes, top to bottom, bit 7 leftmost; blank tiles have no row |
| `images`  | `id`, `asset_type`, `name`, `position`, `width`, `height`, `pixels`, `updated_at` | `asset_type` is `evlores_image`; `pixels` is one byte per pixel, row by row (they are only packed two to a byte in the export); `name` is unique ignoring case |

### API

| Method   | Route                       | Does                                                      |
| -------- | --------------------------- | --------------------------------------------------------- |
| `GET`    | `/api/state`                | Palette, formats, every asset, the name rules             |
| `GET`    | `/api/export`               | res.h / res.c as generated now, and whether the disk has caught up |
| `PUT`    | `/api/font/text`            | `{ "text": "..." }`                                       |
| `PUT`    | `/api/font/tiles`           | `{ "tiles": { "65": [10 rows] } }`; an all-zero tile is deleted |
| `POST`   | `/api/images`               | New image; `name`, `width`, `height` are optional         |
| `PATCH`  | `/api/images/{id}`          | Rename: `{ "name": "skull" }`                             |
| `PUT`    | `/api/images/{id}/pixels`   | `{ "width": 64, "height": 32, "pixels": "0f0f..." }`, one hex digit per pixel |
| `DELETE` | `/api/images/{id}`          | Delete an image                                           |

Bad input gets a `400` with `{ "error": "..." }`.
