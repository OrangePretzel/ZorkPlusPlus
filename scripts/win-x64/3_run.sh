#!/bin/bash

SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )/.."
PROJECT_DIR="$SCRIPT_DIR/.."
BUILD_DIR="$PROJECT_DIR/build"

. $SCRIPT_DIR/common.sh

exe_path="$BUILD_DIR/source/Zork.ConsoleApp/zork.exe"

echo "==============================================================================="
echo "Running [$exe_path]"
echo "==============================================================================="
$exe_path
echo "==============================================================================="
