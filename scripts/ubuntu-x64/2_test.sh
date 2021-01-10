#!/bin/bash

SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )/.."
PROJECT_DIR="$SCRIPT_DIR/.."
BUILD_DIR="$PROJECT_DIR/build"

. $SCRIPT_DIR/common.sh

test_projects=(
	"Zork.Core.Tests"
)
for test_project in ${test_projects[@]}; do
	test_path="$BUILD_DIR/tests/$test_project/$test_project"
	
	echo "==============================================================================="
	echo "Running Test Project: $test_project"
	echo "==============================================================================="
	$test_path
	echo "==============================================================================="
	echo
done
