cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(Aspose.Slides.Cpp.QtExample CXX)

if(DEFINED ASPOSE_SLIDES_PATH)
    message(STATUS "Using ASPOSE_SLIDES_PATH value from cmake: ${ASPOSE_SLIDES_PATH}")
elseif(DEFINED ENV{ASPOSE_SLIDES_PATH})
    set(ASPOSE_SLIDES_PATH $ENV{ASPOSE_SLIDES_PATH})
    message(STATUS "ASPOSE_SLIDES_PATH: ${ASPOSE_SLIDES_PATH}")
else()
    message(FATAL_ERROR "ASPOSE_SLIDES_PATH not set")
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

find_package(Qt5 COMPONENTS Widgets REQUIRED PATHS ${Qt5_DIR})

set(target "${PROJECT_NAME}")

add_executable(${target}
    "${CMAKE_CURRENT_SOURCE_DIR}/../Source/QtWidgets/main.cpp"
)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${target})

if (MSVC)
    target_sources(${target} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/aspose_types.natvis")
endif()

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

target_link_libraries(${target} PRIVATE Qt5::Widgets)

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

if (WIN32)
    get_target_property(QT5_QMAKE_EXECUTABLE Qt5::qmake IMPORTED_LOCATION)
    get_filename_component(QT5_WINDEPLOYQT_EXECUTABLE ${QT5_QMAKE_EXECUTABLE} PATH)
    set(QT5_WINDEPLOYQT_EXECUTABLE "${QT5_WINDEPLOYQT_EXECUTABLE}/windeployqt.exe")

    add_custom_command(TARGET ${target} POST_BUILD
       COMMAND ${QT5_WINDEPLOYQT_EXECUTABLE} --qmldir ${CMAKE_SOURCE_DIR} $<TARGET_FILE_DIR:${target}>)
endif(WIN32)
