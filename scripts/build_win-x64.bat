@echo off
set SCRIPT_DIR=%~dp0

set PROJECT_DIR="%SCRIPT_DIR%\\.."
set BUILD_DIR="%PROJECT_DIR%\\build"

@REM Setup environment to link using msvc 'link.exe'
call C:\"Program Files (x86)"\"Microsoft Visual Studio"\2019\Community\VC\Auxiliary\Build\vcvars64.bat
@REM Print a newline for aesthetic spacing
printf "\n"

@REM Meson
echo "========================================"
meson %BUILD_DIR% --cross-file "%PROJECT_DIR%\\meson\\win-x64.ini"
echo "========================================"
cd %BUILD_DIR%
ninja
echo "========================================"
