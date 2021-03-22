#!/bin/sh
rm -rf build
mkdir build
cd build

# set ASPOSE_SLIDES_PATH environment variables to 
# directory where content of aspose-slides-cpp-YY.MM.zip is extracted
export ASPOSE_SLIDES_PATH="/aspose-slides-cpp-linux-21.2"
export CC=clang
export CXX=clang++

cmake ../
cmake --build . -- -j4


