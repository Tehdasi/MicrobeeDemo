"""Build a self-booting Microbee DS80 disk image (.dsk) from an SDCC .ihx file.

The program must start at 0x0080 with the boot loader from src/crt0.s.  Its
first 512 bytes become the boot sector (cylinder 0, side 0, sector 1); the rest
follows in order, 10 sectors per cylinder, all on side 0.  That matches the
boot ROM's read routine, which maps its track numbers 0-39 to side 0.

Given the linker's .map file, it also checks that the RAM variables (which
follow the program) end below the stack.

Usage: python mkdisk.py program.ihx output.dsk [program.map]
"""
import re
import sys

LOAD_ADDR = 0x0080          # where the boot ROM puts the boot sector
ROM_WORKSPACE = 0xDE00      # the boot ROM's variables/code live above this while loading
STACK_TOP = 0xF000          # crt0.s: the stack grows down from here; video RAM is above
STACK_RESERVE = 0x200       # bytes kept free below STACK_TOP for the stack

CYLINDERS = 80
SIDES = 2
SECTORS = 10
SECTOR_SIZE = 512
TRACK_SIZE = SECTORS * SECTOR_SIZE
FILLER = 0xE5


def read_ihx(path):
    """Return {address: byte} from an Intel HEX file, rejecting overlaps."""
    mem = {}
    base = 0
    with open(path) as f:
        for line_no, line in enumerate(f, 1):
            line = line.strip()
            if not line:
                continue
            if not line.startswith(':'):
                sys.exit(f"{path}:{line_no}: not an Intel HEX record")
            rec = bytes.fromhex(line[1:])
            count, addr, rtype = rec[0], (rec[1] << 8) | rec[2], rec[3]
            data = rec[4:4 + count]
            if sum(rec) & 0xFF:
                sys.exit(f"{path}:{line_no}: checksum error")
            if rtype == 0x00:
                for i, b in enumerate(data):
                    a = base + addr + i
                    if a in mem:
                        sys.exit(f"{path}: two areas overlap at 0x{a:04X} "
                                 "(is the boot loader in crt0.s over 128 bytes?)")
                    mem[a] = b
            elif rtype == 0x01:
                break
            elif rtype == 0x02:
                base = ((data[0] << 8) | data[1]) << 4
            elif rtype == 0x04:
                base = ((data[0] << 8) | data[1]) << 16
    return mem


def build_image(mem):
    if not mem:
        sys.exit("program is empty")
    lo, hi = min(mem), max(mem)
    if lo != LOAD_ADDR:
        sys.exit(f"program starts at 0x{lo:04X}, expected 0x{LOAD_ADDR:04X} (link with src/crt0.s first)")
    size = hi + 1 - LOAD_ADDR
    sectors = (size + SECTOR_SIZE - 1) // SECTOR_SIZE
    if LOAD_ADDR + sectors * SECTOR_SIZE > ROM_WORKSPACE:
        sys.exit(f"program too big: ends at 0x{hi:04X}, must load below 0x{ROM_WORKSPACE:04X}")
    image = bytearray(sectors * SECTOR_SIZE)
    for a, b in mem.items():
        image[a - LOAD_ADDR] = b
    return image, hi


def check_ram(map_path):
    """End of the RAM variables (_DATA up to _HEAP), which must stay clear of the stack.

    Non-const initialised globals take RAM as well as image space: crt0 copies
    them from _INITIALIZER to _INITIALIZED at start-up."""
    with open(map_path) as f:
        m = re.search(r"^\s*([0-9A-F]+)\s+s__HEAP\b", f.read(), re.M)
    if not m:
        sys.exit(f"{map_path}: no s__HEAP symbol (link with src/crt0.s first)")
    end = int(m.group(1), 16)
    limit = STACK_TOP - STACK_RESERVE
    if end > limit:
        sys.exit(f"RAM variables end at 0x{end:04X}, {end - limit} bytes into the stack's "
                 f"0x{STACK_RESERVE:X} bytes below 0x{STACK_TOP:04X}. Make large read-only "
                 "arrays const so they need no RAM copy.")
    return end


def write_dsk(path, image):
    """Standard (non-extended) CPCEMU DSK, as MAME's floppy loader reads it."""
    track_bytes = 0x100 + TRACK_SIZE
    out = bytearray(0x100)
    out[0:34] = b"MV - CPCEMU Disk-File\r\nDisk-Info\r\n"
    out[0x22:0x30] = b"mb2 mkdisk.py\0"
    out[0x30] = CYLINDERS
    out[0x31] = SIDES
    out[0x32] = track_bytes & 0xFF
    out[0x33] = track_bytes >> 8

    padded = image + bytes([FILLER]) * (CYLINDERS * TRACK_SIZE - len(image))
    blank = bytes([FILLER]) * TRACK_SIZE
    for cyl in range(CYLINDERS):
        for side in range(SIDES):
            info = bytearray(0x100)
            info[0:12] = b"Track-Info\r\n"
            info[0x10] = cyl
            info[0x11] = side
            info[0x14] = 2              # N=2: 512-byte sectors
            info[0x15] = SECTORS
            info[0x16] = 0x17           # GAP#3
            info[0x17] = FILLER
            for s in range(SECTORS):
                e = 0x18 + s * 8
                info[e:e + 4] = bytes([cyl, side, s + 1, 2])
            start = cyl * TRACK_SIZE
            out += info + (padded[start:start + TRACK_SIZE] if side == 0 else blank)

    with open(path, "wb") as f:
        f.write(out)


def main():
    if len(sys.argv) not in (3, 4):
        sys.exit(__doc__)
    ihx, dsk = sys.argv[1], sys.argv[2]
    ram_end = check_ram(sys.argv[3]) if len(sys.argv) == 4 else None
    image, hi = build_image(read_ihx(ihx))
    write_dsk(dsk, image)
    print(f"{dsk}: program 0x{LOAD_ADDR:04X}-0x{hi:04X} "
          f"({hi + 1 - LOAD_ADDR} bytes, {len(image) // SECTOR_SIZE} sectors)")
    if ram_end is not None:
        print(f"RAM variables end at 0x{ram_end:04X}, {STACK_TOP - ram_end} bytes free below the stack top")


if __name__ == "__main__":
    main()
