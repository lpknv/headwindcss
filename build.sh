#!/usr/bin/env bash
set -e

clear

mkdir -p build
cd build
gcc ../../src/main.c -o ./main
./main
cd ..