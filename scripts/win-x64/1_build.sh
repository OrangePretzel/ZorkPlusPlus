#!/bin/bash
SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )/.."

. $SCRIPT_DIR/common.sh

powershell -Command "Invoke-Expression ./scripts/win-x64/1_build.bat"