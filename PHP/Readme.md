# Demo examples of using Aspose.Slides for C++ in PHP

This example demonstrates PHP extension that allows to use Aspose.Slides for C++ library.
This sample code can be used as a skeleton for developing other specific applications that use the different capabilities of the library.

## How to build example

### Windows platform
 
1. Download Aspose.Slides for C++ library zip distribution for the platform: https://downloads.aspose.com/slides/cpp.

2. Download precompiled PHP binaries. It should be downloaded from https://windows.php.net/download/ and must match the compiler that you will build the example. Depends on the web server used, it my be a "thread safe" or a "not thread safe" type of distribution. Please, read the explanations about "TS" and "NTS" difference at https://windows.php.net/download/.

   There are two packages to download:
   1. Main package (PHP itself).
   2. Development package (precompiled libraries and headers files).

   For example, these two packages may be: php-8.3.7-nts-Win32-vs16-x64.zip (main package 'nts') and php-devel-pack-8.3.7-nts-Win32-vs16-x64.zip (development package 'nts').

3. Setup variable list in the ```setup_php_environment.bat``` script.
   
   **ASPOSE_SLIDES_PATH**:
   
   The path to the Aspose.Slides for C++ distribution folder.
 
   For example, Aspose.Slides for C++ version 24.5 comes in zip archive named aspose-slides-cpp-windows-24.5, this archive should be extracted somewhere and the path that folder should be assigned to that variables.

   **PHP_PATH**:
   
   The path to the PHP main package folder.

   Suppose, that main package archive 'php-8.3.7-nts-Win32-vs16-x64.zip' is extracted at 'c:/tools/php'. Then, variable's values should be:
   PHP_PATH=C:/tools/php/php-8.3.7-nts-Win32-vs16-x64

   **PHP_DEV_PACK_PATH**:

   The path to the PHP development package folder.
   
   Development package archive 'php-devel-pack-8.3.7-nts-Win32-vs16-x64.zip' is probably extracted at 'c:/tools/php'. Then, variable's values should be:
   PHP_DEV_PACK_PATH=c:\tools\php\php-devel-pack-8.3.7-nts-Win32-vs16-x64\php-8.3.7-devel-vs16-x64\
     
4. Build the PHP extension using the ```build_windows_x64.bat``` script. The resulting shared extension library along with Aspose.Slides for the C ++ binaries will be written to the tests folder.

### Linux platform

1. Download Aspose.Slides for C++ library zip distribution for the platform: https://downloads.aspose.com/slides/cpp.

2. Install php-dev package using ```apt-get install php-dev``` command.

3. Setup variable list ```build_linux_clang.sh``` script.

    **ASPOSE_SLIDES_PATH**:
    
    The path to the Aspose.Slides for C++ distribution folder.
 
    For example, Aspose.Slides for C++ version 24.5 comes in zip archive named aspose-slides-cpp-linux-24.5, this archive should be extracted somewhere and the path that folder should be assigned to that variables.
  
    **PHP_INCLUDE_PATH**:
    
    The path to the PHP 'include' directory.
    This path can be obtained by command ```php-config --include-dir```.

4. Build the PHP extension using the ```build_linux_clang.sh``` script.

## How to test extension and run sample web applicaion

The 'tests' folder contains examples of using the PHP extension. 

* The scripts test the extension with 'php' command:
   * Windows: ```run_test.bat```
   * Linux: ```run_test.sh```

* The scripts show how to run a simple PHP Web application using the built-in php web server:
   * Windows: ```run_server.bat```
   * Linux: ```run_server.sh``` 

### Sample PHP Web Application

The sample PHP Web Application contains two files:
* index.html
* converter.php
   
Sample web application works as follows: it asks to upload a presentation file. After submitting the form, web server (PHP script) translates the file to the PDF format and sends the converted file back to client.

The extension was written with supporting Aspose.Slides for C++ license. If you have a license file, you can set a path to the file
to the variable aspose_slides_cpp_license. The aspose_slides_cpp_license variable is located in the AsposeSlidesCppExtension.ini file for Windows(AsposeSlidesCppExtension.ini.linux for Linux). The extension will check the license at initialization and displays a corresponding message.