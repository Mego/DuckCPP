#!/bin/bash

# Exit on failure
set -e

# Set CXX environment variable to g++ if not set
: ${CXX:=g++}

# Prepare directories
mkdir -p bin
cd bin

# Compile
$CXX -c -o Duck.o ../src/Duck.cpp -I../include/ -std=c++11

# Link
$CXX -o duck Duck.o
