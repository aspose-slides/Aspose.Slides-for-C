# set ASPOSE_SLIDES_PATH environment variables to 
# directory where content of aspose-slides-cpp-linux-YY.MM.zip is extracted
export ASPOSE_SLIDES_PATH="/aspose-slides-cpp-linux-24.5"
export PHP_INCLUDE_PATH="/usr/include/php/20190902"

export CC=clang
export CXX=clang++

rm -rf "build"
mkdir "build"
cd "build"
cmake .. -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release
if [ $? -eq 0 ]
then
  cmake --build . --config Release -- -j4
fi
