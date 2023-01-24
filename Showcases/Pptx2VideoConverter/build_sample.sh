#!/bin/sh
mkdir build
cd build

export CC=clang
export CXX=clang++

cmake ../
cmake --build . --config Release -- -j4

cd ..
