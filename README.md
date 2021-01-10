# Overview
Zork Plus Plus is text based adventure game. Play it!
This project is designed to be used as a template for future C++ projects

# Download & Installation Options
No download options exist yet. You can build from source following the instructions below.

# Building From Source
## Dependencies
To build from source you will require the following:
1. Python 3 (`python`) available from the command line
2. Clang (`clang++` or `clang-cl`) available from the command line [https://clang.llvm.org/]

## Build Steps
Run the following commands from the repository root directory:
1. Run `scripts/<platform>/0_setup.sh` to perform first time setup (this is only required for the first build)
2. Run `scripts/<platform>/1_build.sh` to build the project
3. Run `scripts/<platform>/2_test.sh` to run the unit tests

## Building on Windows
In addition to the dependencies above, building on Windows requires you have Microsoft's C++ toolchain installed. The easiest way to obtain the toolchain is to install Visual Studio with the C++ options included.
