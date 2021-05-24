call setup_php_environment.bat

rmdir /Q /S build
mkdir build
cd build
cmake .. -G "Visual Studio 15 2017 Win64"
if %errorlevel% neq 0 goto error
cmake --build . --config Release --parallel 5
:error

copy Release\Aspose.Slides.Cpp.PhpExtension.dll ..\tests
copy Release\Aspose.Slides_vc14x64.dll ..\tests
copy Release\aspose_cpp_vc14x64.dll ..\tests