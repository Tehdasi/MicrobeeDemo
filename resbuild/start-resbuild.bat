@echo off
setlocal EnableExtensions EnableDelayedExpansion

rem Starts the Resbuild server in this window and opens the page in Firefox once it answers.
rem Close the window or press Ctrl+C to stop the server.

set "PORT=5174"
set "URL=http://localhost:%PORT%/"

rem The script re-runs itself in a second window to do the waiting and the launching,
rem so the server can keep this window (and its log output) for itself.
if /i "%~1"=="--open-when-ready" goto :open_when_ready

where dotnet >nul 2>&1
if errorlevel 1 (
    echo [Resbuild] dotnet was not found on PATH. Install the .NET SDK first: https://dotnet.microsoft.com/download
    pause
    exit /b 1
)

start "Resbuild browser launcher" /min "%~f0" --open-when-ready
echo [Resbuild] Starting the server on %URL%
echo [Resbuild] Press Ctrl+C to stop.
echo.
dotnet run --project "%~dp0server\Resbuild.Server.csproj" --no-launch-profile
exit /b %errorlevel%


rem ---------------------------------------------------------------- launcher
rem This half runs in the second window. START opens a .bat with CMD /K, so each exit
rem here is a plain EXIT: it closes that window instead of leaving a prompt behind.

:open_when_ready
rem Give the server up to a minute to come up (a first build can take a while).
for /l %%i in (1,1,60) do (
    curl.exe -s -o nul -m 2 "%URL%api/state" && goto :open_browser
    timeout /t 1 /nobreak >nul
)
echo [Resbuild] The server did not answer on %URL% - not opening the browser.
timeout /t 5 /nobreak >nul
exit 1

:open_browser
call :find_firefox
if not defined FIREFOX (
    echo [Resbuild] Firefox was not found; opening %URL% in the default browser instead.
    start "" "%URL%"
    timeout /t 3 /nobreak >nul
    exit 0
)
start "" "%FIREFOX%" "%URL%"
exit 0

:find_firefox
set "FIREFOX="
for %%p in (
    "%ProgramFiles%\Mozilla Firefox\firefox.exe"
    "%ProgramFiles(x86)%\Mozilla Firefox\firefox.exe"
    "%LOCALAPPDATA%\Mozilla Firefox\firefox.exe"
) do if not defined FIREFOX if exist %%p set "FIREFOX=%%~p"

rem Fall back to wherever Windows has Firefox registered.
if not defined FIREFOX (
    for /f "tokens=2,*" %%a in ('reg query "HKCU\SOFTWARE\Microsoft\Windows\CurrentVersion\App Paths\firefox.exe" /ve 2^>nul ^| find "REG_SZ"') do set "FIREFOX=%%~b"
)
if not defined FIREFOX (
    for /f "tokens=2,*" %%a in ('reg query "HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\App Paths\firefox.exe" /ve 2^>nul ^| find "REG_SZ"') do set "FIREFOX=%%~b"
)
if defined FIREFOX if not exist "!FIREFOX!" set "FIREFOX="
exit /b 0
