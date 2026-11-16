@echo off
rem Build build\mb2.dsk - a self-booting Microbee 128k disk.
rem Needs SDCC (sdcc, sdasz80) and Python 3 on the PATH.
setlocal
cd /d "%~dp0"

set OUT=build
set NAME=mb2
set CFLAGS=-mz80 --opt-code-speed -Isrc -D__MBEE
rem Code follows the 128-byte boot loader; RAM variables follow the code.
set LDFLAGS=-mz80 --no-std-crt0 --code-loc 0x0100 --data-loc 0

if not exist %OUT% mkdir %OUT%

sdasz80 -plosgff -o %OUT%\crt0.rel src\crt0.s || goto :error

rem Compile every file even after a failure, so all the errors get shown.
set FAILED=
set OBJS=%OUT%\crt0.rel
call :compile src\mbee\mbee.c
for %%f in (src\*.c) do call :compile %%f
if defined FAILED goto :error

sdcc %LDFLAGS% -o %OUT%\%NAME%.ihx %OBJS% || goto :error
rem The .map lets mkdisk check that RAM variables stay clear of the stack.
python tools\mkdisk.py %OUT%\%NAME%.ihx %OUT%\%NAME%.dsk %OUT%\%NAME%.map || goto :error

echo Built %OUT%\%NAME%.dsk
exit /b 0

:error
echo BUILD FAILED
exit /b 1

rem Compile one C file.  SDCC 4.6.0's sdasz80 crashes without a message on
rem some inline-asm syntax errors, so on failure asmcheck.py finds the line.
:compile
echo %1
set OBJS=%OBJS% %OUT%\%~n1.rel
if exist %OUT%\%~n1.asm del %OUT%\%~n1.asm
sdcc %CFLAGS% -c -o %OUT%\%~n1.rel %1 && exit /b 0
set FAILED=1
if exist %OUT%\%~n1.asm python tools\asmcheck.py %OUT%\%~n1.asm
exit /b 0
