#!/bin/bash

# Exit on failure
set -e

# Prepare directories
mkdir -p bin
cd bin

# Compile
g++ -c -o duck.o ../src/duck.cpp -I../include/ -std=c++11

# Link
g++ -o duck duck.o
