@echo off
rem Boot build\mb2.dsk in MAME.  Extra arguments go to MAME, e.g.  run -debug
rem Set MAME_DIR if MAME isn't in C:\apps\mame, MACHINE to use another model.
setlocal
if "%MAME_DIR%"=="" set MAME_DIR=C:\apps\mame
if "%MACHINE%"=="" set MACHINE=mbee128p
set DSK=%~dp0build\mb2.dsk

if not exist "%DSK%" call "%~dp0build.bat" || exit /b 1

pushd "%MAME_DIR%"
rem "%MAME_DIR%\mame.exe" %MACHINE% -window -nomaximize -nounevenstretch -nofilter -skip_gameinfo -flop1 "%DSK%" %*

"%MAME_DIR%\mame.exe" %MACHINE% -volume 0 -window -nosamples -nounevenstretch -nofilter -nomaximize -skip_gameinfo  -intscalex 3 -intscaley 5 -flop1 "%DSK%" %*

popd
