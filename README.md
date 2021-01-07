# Overview
Zork Plus Plus is text based adventure game. Play it!
This project is designed to be used as a template for future C++ projects

# Download & Installation Options
No download options exist yet. You can build from source following the instructions below.

# Building From Source
## Prerequisites
To build from source you will require the following:
1. Python 3 (`python`) available from the command line (required by Meson)
2. Ninja (`ninja`) available from the command line [https://ninja-build.org/]
3. Meson Build System (`meson`) available from the command line [https://mesonbuild.com]
4. Clang (`clang-cl`) available from the command line [https://clang.llvm.org/]

## Generic Build Steps
Run the following commands from the root directory:
1. `meson build`
2. `cd build`
3. `ninja`

## Building on Windows
It is recommended to build on Windows using Clang (`clang-cl.exe`) as the C++ compiler, and MSVC as the linker.
1. Ensure Clang (`clang-cl.exe`) is available from the command line
2. Examine & run the script `scripts/build_win-x64.bat` from the root project directory to build

## Building on Unix
Building on Unix is currently untested.
Follow the generic build steps above, and create a pull request to update this section.
If you successfully build on Unix please update/create build scripts and submit a PR
