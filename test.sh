#!/bin/bash

# The script aborts with any errors.
set -e

PROJECT_ROOT=$(dirname "$(realpath "$0")")

BUILD_DIR="$PROJECT_ROOT/build"

if [ ! -d "$BUILD_DIR" ]; then
    echo "Creating build directory: $BUILD_DIR"
    mkdir -p "$BUILD_DIR"
else
    rm -rf $BUILD_DIR/*
fi

cd "$BUILD_DIR"

cmake ..

cmake --build .

if [ -d "$BUILD_DIR/tests" ]; then
    cd $BUILD_DIR/tests
    echo "Running ctest..."
    ctest --output-on-failure
else
    echo "tests directory not found."
fi