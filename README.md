A demo done for Syntax 2026.

Came in 5th.

Designed to build in windows. 
Uses sdcc.
Mame was used to debug for mbee compiles, and vs for windows.
Node is used for the rebuilding random data and code.
Python is used in the build to make disk images and deal with sdcc's buggy assembler.
The target machine is a Premium 128k. Mainly cause that was what I had the roms for.

resbuild was used to edit some images, eh, that didn't work so well.

To build:
run b.bat

To run:
run r.bat

To rebuild all the resources, and some of the generated code:
run rr.bat

For ease of development it's designed so that all the microbee specific stuff is in mbee.c/h, swapping that in with win.c/h will allow the same code to run in windows with raylib. So you get to utilize the quicker compile and debugger in windows.