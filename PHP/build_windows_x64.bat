call setup_php_environment.bat

rmdir /Q /S build
mkdir build
cd build
cmake .. -G "Visual Studio 16 2019"
if %errorlevel% neq 0 goto error
cmake --build . --config Release --parallel 4
:error

copy Release\Aspose.Slides.Cpp.PhpExtension.dll ..\tests
copy Release\Aspose.Slides_vc14x64.dll ..\tests
copy Release\codeporting.translator.cs2cpp.framework_vc14x64.dll ..\tests