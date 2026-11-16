;;; crt0.s - boot sector + C start-up for a self-booting Microbee 128k disk
;;;
;;; The 128k boot ROM copies its disk code to RAM at 0xE000, reads logical
;;; track 0 / sector 1 (512 bytes) to 0x0080 and jumps there.  That sector is
;;; the first 512 bytes of this program: the loader below uses the ROM's read
;;; routine to pull the rest of the image (sector 2 onwards) in to 0x0280, then
;;; switches to an all-RAM memory map and starts the C runtime.
;;;
;;; No CP/M is involved - the program owns the whole machine.  Interrupts stay
;;; disabled.

        .module crt0
        .globl  _main

        ;; Boot ROM entry points (jump table at 0xE000, valid while booting)
ROM_RESTART     = 0xE000        ; restart the boot ROM
ROM_PUTC        = 0xE00C        ; print character in C
ROM_PUTS_WAIT   = 0xE033        ; print string at HL, wait for RETURN
ROM_READ        = 0xE039        ; read BC bytes from track D sector E to HL; Z = ok

LOAD_ADDR       = 0x0280        ; first byte after the boot sector
STACK_TOP       = 0xF000        ; RAM ends where video RAM starts
MEMMAP          = 0x04          ; port 0x50: RAM 0000-EFFF, video F000-FFFF, ROM off

;;; ---------------------------------------------------------------------------
;;; Boot sector loader: 0x0080-0x00FF (C code follows from 0x0100)
;;; ---------------------------------------------------------------------------
        .area   _HEADER (ABS)
        .org    0x0080

boot:
        ld      sp, #0x0080
        ld      de, #0x0002             ; logical track 0, sector 2
        ld      hl, #LOAD_ADDR
        ld      bc, #s__TAIL - LOAD_ADDR  ; bytes left to load (whole image)
        call    ROM_READ
        jr      nz, boot_failed
        di                              ; the ROM read routine re-enables them
        ld      a, #MEMMAP
        out     (0x50), a
        jp      start

boot_failed:
        ld      c, #0x1a                ; clear screen
        call    ROM_PUTC
        ld      hl, #boot_msg
        call    ROM_PUTS_WAIT
        jp      ROM_RESTART

boot_msg:
        .ascii  "Disk read error - press RETURN"
        .db     0x80

;;; ---------------------------------------------------------------------------
;;; Linker area order.  Everything up to _TAIL is part of the disk image;
;;; RAM-only areas follow it.
;;; ---------------------------------------------------------------------------
        .area   _CODE
        .area   _HOME
        .area   _INITIALIZER
        .area   _GSINIT
        .area   _GSFINAL
        .area   _TAIL                   ; empty: marks the end of the image
        .area   _DATA
        .area   _INITIALIZED
        .area   _BSEG
        .area   _BSS
        .area   _HEAP

;;; ---------------------------------------------------------------------------
;;; C runtime start-up (runs after the whole image is loaded)
;;; ---------------------------------------------------------------------------
        .area   _CODE

start:
        ld      sp, #STACK_TOP

        ;; zero all RAM variables (_DATA up to the heap)
        ld      hl, #s__HEAP
        ld      de, #s__DATA
        or      a
        sbc     hl, de
        ld      b, h
        ld      c, l
        ld      a, b
        or      c
        jr      z, 2$
        ld      h, d
        ld      l, e
        ld      (hl), #0
        inc     de
        dec     bc
        ld      a, b
        or      c
        jr      z, 2$
        ldir
2$:
        call    gsinit                  ; copy initialised globals
        call    _main

        ;; main() returned: stop here
3$:
        halt
        jr      3$

        .area   _GSINIT
gsinit:
        ld      bc, #l__INITIALIZER
        ld      a, b
        or      c
        jr      z, gsinit_next
        ld      de, #s__INITIALIZED
        ld      hl, #s__INITIALIZER
        ldir
gsinit_next:

        .area   _GSFINAL
        ret
