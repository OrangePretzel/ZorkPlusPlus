#!/bin/bash

SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )/.."
PROJECT_DIR="$SCRIPT_DIR/.."
BUILD_DIR="$PROJECT_DIR/build"

. $SCRIPT_DIR/common.sh

echo "==============================================================================="
python -m pip install --upgrade pip
pip install ninja
pip install meson
echo "==============================================================================="
