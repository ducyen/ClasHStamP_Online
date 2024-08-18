@echo off
setlocal

:: Retrieve command line arguments
set "WORKING_DIR=%~dp1"
set "SAMPLE_DIR=%2"
set "GEOMETRY=%3"

echo Working Directory: %WORKING_DIR%
echo Sample Directory: %SAMPLE_DIR%
echo Geometry: %GEOMETRY%

:: Define sample home path
set "SAMPLE_HOME=samples\%SAMPLE_DIR%"

echo Running command: .\astah-uml\astah-command.bat -f %SAMPLE_HOME%\Design.asta -image -o %SAMPLE_HOME%\Image -t png -dpi 72
.\astah-uml\astah-command.bat -f %SAMPLE_HOME%\Design.asta -image -o %SAMPLE_HOME%\Image -t png -dpi 72

:: Navigate to the sample directory
cd "%WORKING_DIR%\samples\%SAMPLE_DIR%\C"
if errorlevel 1 exit /b

:: Attempt to make the build
make
if errorlevel 1 (
    echo Make command failed. Press any key to continue...
    pause
    exit /b 1
)

:: Navigate back to the working directory
cd %WORKING_DIR%
if errorlevel 1 exit /b

:: Define the path to the executable program
set "PROGRAM_PATH=%WORKING_DIR%\samples\%SAMPLE_DIR%\C\my_program.exe"
echo Program Path: %PROGRAM_PATH%

:: Execute the program if it exists
if exist "%PROGRAM_PATH%" (
    echo Executing program...
    "%PROGRAM_PATH%" "%WORKING_DIR%\samples\%SAMPLE_DIR%\Image\Design" "%WORKING_DIR%\samples\%SAMPLE_DIR%\TransImg\Design"
) else (
    echo Error: Program not found at %PROGRAM_PATH%
)

endlocal
