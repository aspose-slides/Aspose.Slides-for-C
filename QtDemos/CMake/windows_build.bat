mkdir build
cd build

:: set Qt5_DIR to your Qt installation 
SET Qt5_DIR=d:/Qt/5.14.2/msvc2017_64/lib/cmake/Qt5

:: set ASPOSE_SLIDES_PATH environment variables to 
:: directory where content of aspose-slides-cpp-YY.MM.zip is extracted
SET ASPOSE_SLIDES_PATH=c:/aspose-slides-cpp-21.2

cmake .. -A x64 -G "Visual Studio 15 2017"
