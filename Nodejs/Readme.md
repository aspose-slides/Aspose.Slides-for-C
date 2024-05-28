# Demo examples of using Aspose.Slides for C++ in Node.js

This example demonstrates a C++ Node.js addon that allows to use Aspose.Slides for C++ library. This sample code can be used as a skeleton for developing other specific applications that use different features of the library.

## How to build C++ addon
 
1. Download Aspose.Slides for C++ library zip distribution for a platform that you use: https://downloads.aspose.com/slides/cpp.

2. Install [CMake](https://github.com/Kitware/CMake/releases/).

3. Setup variables in the ```package.json``` file:
   
   * The Path to the Aspose.Slides for C++ distribution folder:
   
      For example, Aspose.Slides for C++ version 24.5 comes in a zip archive named aspose-slides-cpp-windows-24.5, this archive should be extracted somewhere and the path that folder should be assigned to that variables.

      Change **ASPOSE_SLIDES_PATH** variable in the section corresponding to your OS (now available build:win32 and build:nix). You can find more details on run-script-os package [here](https://www.npmjs.com/package/run-script-os).

   * Set a CMake build system generator:

     You can specify a CMake build system generator after -G option. You can find more details on CMake generators [here](https://cmake.org/cmake/help/latest/manual/cmake-generators.7.html#manual:cmake-generators(7)).

4. Download Node.js dependencies:

   ```npm install```

5. Build the C++ addon using the following command:

   ```npm run build```

## How to test addon and run sample web applicaion

The 'tests' folder contains examples of using the C++ Node.js addon. 

* In order to download dependencies to test the C++ addon, use the following command:

   ```npm install```

* The command tests the C++ Node.js addon locally:
   
   ```node test.js```

### Sample Node.js Web Application

Use the following command to run the Node.js Web Application: ```node app.js```

The web application contains two files:
* index.html
* app.js
   
The sample web application works as follows: it asks to upload a presentation file. After submitting the form, the Node.js server translates the file to the PDF format and sends the converted file back to the client.
