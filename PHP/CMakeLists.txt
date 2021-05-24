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

set(CMAKE_GENERATOR_PLATFORM x64)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
set(ASPOSE_SLIDES_LIBRARIES_PATH "${ASPOSE_SLIDES_PATH}/lib")

if (MSVC AND ${CMAKE_VERSION} VERSION_LESS "3.13.5")
    message (WARNING "You must manually set the Debugging Environment to PATH=${ASPOSE_SLIDES_LIBRARIES_PATH}/$(Configuration);%PATH% to run the examples")
endif()

include(GuessCompilerPrefix)
GUESS_COMPILER_PREFIX(compiler_suffix)

if (MSVC)
    find_library(asposecpplib_debug
        NAMES aspose_cpp_${compiler_suffix}d
        PATHS ${ASPOSE_SLIDES_LIBRARIES_PATH}
        PATH_SUFFIXES Debug
        NO_DEFAULT_PATH
    )

    find_library(aspose.slides_debug
        NAMES Aspose.Slides_${compiler_suffix}d
        PATHS ${ASPOSE_SLIDES_LIBRARIES_PATH}
        PATH_SUFFIXES Debug
        NO_DEFAULT_PATH
    )
endif()

find_library(asposecpplib_release
    NAMES aspose_cpp_${compiler_suffix}
    PATHS ${ASPOSE_SLIDES_LIBRARIES_PATH}
    PATH_SUFFIXES Release
    NO_DEFAULT_PATH
)

find_library(aspose.slides_release
    NAMES Aspose.Slides_${compiler_suffix}
    PATHS ${ASPOSE_SLIDES_LIBRARIES_PATH}
    PATH_SUFFIXES Release
    NO_DEFAULT_PATH
)

if (NOT asposecpplib_release)
    message(FATAL_ERROR "Library aspose_cpp_${compiler_suffix} not found in ${ASPOSE_SLIDES_LIBRARIES_PATH}")
endif()

if (NOT aspose.slides_release)
    message(FATAL_ERROR "Library Aspose.Slides_${compiler_suffix} not found in ${ASPOSE_SLIDES_LIBRARIES_PATH}")
endif()

# package configuration for pre-build php
if (MSVC)
add_library(php SHARED IMPORTED)

set_target_properties(php PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${PHP_INCLUDE_PATH};${PHP_INCLUDE_PATH}/main;${PHP_INCLUDE_PATH}/TSRM;${PHP_INCLUDE_PATH}/Zend;"
)

set_property(TARGET php APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(php PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${PHP_LIB_PATH}/php7.lib"
  IMPORTED_LOCATION_DEBUG "${PHP_DLL_PATH}/php7.dll"
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

target_include_directories(${target} SYSTEM PRIVATE
    "${ASPOSE_SLIDES_PATH}/include/asposecpplib"
    "${ASPOSE_SLIDES_PATH}/include/aspose.slides.cpp"
)

set_target_properties(${target} PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
    VS_DEBUGGER_WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    # VS_DEBUGGER_ENVIRONMENT property works only for cmake 3.13 and above.
    VS_DEBUGGER_ENVIRONMENT "PATH=${ASPOSE_SLIDES_LIBRARIES_PATH}/$(Configuration);%PATH%")

target_link_libraries(${target} PRIVATE php)

if (MSVC)
    target_link_libraries(${target} PRIVATE
        debug ${asposecpplib_debug}
        debug ${aspose.slides_debug}
        optimized ${asposecpplib_release}
        optimized ${aspose.slides_release}
    )
else()
    target_link_libraries(${target} PRIVATE
        ${asposecpplib_release}
        ${aspose.slides_release}
    )
endif()

if (MSVC)
    FILE(GLOB files "${ASPOSE_SLIDES_LIBRARIES_PATH}/*dll")
    FOREACH(file ${files})
        ADD_CUSTOM_COMMAND(TARGET ${target} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${file}"             
            $<TARGET_FILE_DIR:${target}>
        )
    ENDFOREACH()
endif()

