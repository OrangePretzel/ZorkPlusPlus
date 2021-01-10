#!/bin/bash

SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )/.."
PROJECT_DIR="$SCRIPT_DIR/.."
BUILD_DIR="$PROJECT_DIR/build"

. $SCRIPT_DIR/common.sh

echo "==============================================================================="
LDFLAGS=-ldl meson $BUILD_DIR --cross-file "$PROJECT_DIR/meson/ubuntu-x64.ini" --prefix=/usr
echo "==============================================================================="
cd $BUILD_DIR
ninja
echo "==============================================================================="
