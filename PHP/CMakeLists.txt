cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(Aspose.Slides.Cpp.PhpExtension CXX)

macro(CheckVariable VARNAME)

if(DEFINED ${VARNAME})
    message(STATUS "Using ${VARNAME} value from cmake: ${${VARNAME}}")
elseif(DEFINED ENV{${VARNAME}})
    set(${VARNAME} $ENV{${VARNAME}})
    message(STATUS "Using ${VARNAME} value from environment: ${${VARNAME}}")
else()
    message(FATAL_ERROR "${VARNAME} not set")
endif()
file(TO_CMAKE_PATH "${${VARNAME}}" ${VARNAME})

endmacro()

CheckVariable(ASPOSE_SLIDES_PATH)
CheckVariable(PHP_INCLUDE_PATH)
if (MSVC)
    CheckVariable(PHP_LIB_PATH)
    CheckVariable(PHP_DLL_PATH)
endif()

find_package(CodePorting.Translator.Cs2Cpp.Framework REQUIRED CONFIG PATHS ${ASPOSE_SLIDES_PATH} NO_DEFAULT_PATH)
find_package(Aspose.Slides.Cpp REQUIRED CONFIG PATHS ${ASPOSE_SLIDES_PATH} NO_DEFAULT_PATH)

file(TO_NATIVE_PATH "${Aspose.Slides.Cpp_DIR}/lib" Aspose.Slides.Cpp_DLL_PATH)
file(TO_NATIVE_PATH "${CodePorting.Translator.Cs2Cpp.Framework_DIR}/lib" CodePorting.Translator.Cs2Cpp.Framework_DLL_PATH)

if (MSVC AND ${CMAKE_VERSION} VERSION_LESS "3.13.5")
    message (WARNING "You must menually set the Debugging Environment to PATH=${Aspose.Slides.Cpp_DLL_PATH};${CodePorting.Translator.Cs2Cpp.Framework_DLL_PATH};%PATH% to run the examples")
endif()

# package configuration for pre-build php
if (MSVC)
add_library(php SHARED IMPORTED)

set_target_properties(php PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${PHP_INCLUDE_PATH};${PHP_INCLUDE_PATH}/main;${PHP_INCLUDE_PATH}/TSRM;${PHP_INCLUDE_PATH}/Zend;"
)

set_property(TARGET php APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(php PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${PHP_LIB_PATH}/php8.lib"
  IMPORTED_LOCATION_DEBUG "${PHP_DLL_PATH}/php8.dll"
  )
target_compile_definitions(php INTERFACE PHP_WIN32 ZEND_WIN32 ZEND_DEBUG=0 ZEND_WIN32_KEEP_INLINE PHP_ATOM_INC)

else()

add_library(php INTERFACE)
set_target_properties(php PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${PHP_INCLUDE_PATH};${PHP_INCLUDE_PATH}/main;${PHP_INCLUDE_PATH}/TSRM;${PHP_INCLUDE_PATH}/Zend;"
)
target_compile_definitions(php INTERFACE ZEND_DEBUG=0 PHP_ATOM_INC)

endif()

set(target "${PROJECT_NAME}")

add_library(${target} SHARED 
AsposeSlidesCppExtension.cpp
)

target_link_libraries(${target} PRIVATE php)
target_link_libraries(${target} PRIVATE CodePorting.Translator.Cs2Cpp.Framework PRIVATE Aspose.Slides.Cpp)

set_target_properties(${target} PROPERTIES CXX_STANDARD 14 CXX_STANDARD_REQUIRED YES)

if (MSVC)
    FILE(GLOB files "${ASPOSE_SLIDES_PATH}/Aspose.Slides.Cpp/lib/*dll" "${ASPOSE_SLIDES_PATH}/CodePorting.Translator.Cs2Cpp.Framework/lib/*dll")
    FOREACH(file ${files})
        ADD_CUSTOM_COMMAND(TARGET ${target} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${file}"             
            $<TARGET_FILE_DIR:${target}>
        )
    ENDFOREACH()
endif()

