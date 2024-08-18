@echo off
setlocal

:: Set working directory
set "WORKING_DIR=%~dp0"

:: Start cmd in a new window with specified dimensions and positions
start "Simulator" /D "%WORKING_DIR%" cmd /c "start_c.bat %WORKING_DIR% %1 %2"

:: Get the PID of the last started process
for /f "tokens=2" %%a in ('tasklist /v /fo list /fi "WINDOWTITLE eq Simulator" ^| find "PID:"') do (
    set "PID=%%a"
)

:: Store the PID in a file
echo %PID% > "%WORKING_DIR%xterm.pid"

:: Wait for my_program to finish (Simulation of 'wait' command)
:WAIT_LOOP
tasklist /fi "PID eq %PID%" | find "%PID%" > nul
if not errorlevel 1 (
    timeout /t 1 > nul
    goto WAIT_LOOP
)

endlocal
