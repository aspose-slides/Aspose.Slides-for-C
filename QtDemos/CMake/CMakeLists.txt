cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(Aspose.Slides.Cpp.QtExample CXX)

set(target "${PROJECT_NAME}")

if(DEFINED ASPOSE_SLIDES_PATH)
    message(STATUS "Using ASPOSE_SLIDES_PATH value from cmake: ${ASPOSE_SLIDES_PATH}")
elseif(DEFINED ENV{ASPOSE_SLIDES_PATH})
    set(ASPOSE_SLIDES_PATH $ENV{ASPOSE_SLIDES_PATH})
    message(STATUS "ASPOSE_SLIDES_PATH: ${ASPOSE_SLIDES_PATH}")
else()
    message(FATAL_ERROR "ASPOSE_SLIDES_PATH not set")
endif()

find_package(CodePorting.Native.Cs2Cpp REQUIRED CONFIG PATHS ${ASPOSE_SLIDES_PATH} NO_DEFAULT_PATH)
find_package(Aspose.Slides.Cpp REQUIRED CONFIG PATHS ${ASPOSE_SLIDES_PATH} NO_DEFAULT_PATH)

file(TO_NATIVE_PATH "${Aspose.Slides.Cpp_DIR}/lib" Aspose.Slides.Cpp_DLL_PATH)
file(TO_NATIVE_PATH "${CodePorting.Native.Cs2Cpp_DIR}/lib" CodePorting.Native.Cs2Cpp_DLL_PATH)

if (MSVC AND ${CMAKE_VERSION} VERSION_LESS "3.13.5")
    message (WARNING "You must menually set the Debugging Environment to PATH=${Aspose.Slides.Cpp_DLL_PATH};${CodePorting.Native.Cs2Cpp_DLL_PATH};%PATH% to run the examples")
endif()

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${target})

find_package(Qt5 COMPONENTS Widgets REQUIRED PATHS ${Qt5_DIR})

add_executable(${target}
    "${CMAKE_CURRENT_SOURCE_DIR}/../Source/QtWidgets/main.cpp"
)

target_compile_options(${target} PRIVATE $<$<CXX_COMPILER_ID:MSVC>:/wd4250 /MP /bigobj /utf-8>)

if (MSVC)
    target_sources(${target} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/aspose_types.natvis")
endif()

set_target_properties(${target} PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
    VS_DEBUGGER_WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    # VS_DEBUGGER_ENVIRONMENT property works only for cmake 3.13 and above.
    VS_DEBUGGER_ENVIRONMENT "PATH=${Aspose.Slides.Cpp_DLL_PATH};${CodePorting.Native.Cs2Cpp_DLL_PATH};%PATH%"
)

target_link_libraries(${target} PRIVATE Qt5::Widgets)
target_link_libraries(${target} PRIVATE CodePorting.Native.Cs2Cpp PRIVATE Aspose.Slides.Cpp)

if (WIN32)
    get_target_property(QT5_QMAKE_EXECUTABLE Qt5::qmake IMPORTED_LOCATION)
    get_filename_component(QT5_WINDEPLOYQT_EXECUTABLE ${QT5_QMAKE_EXECUTABLE} PATH)
    set(QT5_WINDEPLOYQT_EXECUTABLE "${QT5_WINDEPLOYQT_EXECUTABLE}/windeployqt.exe")

    add_custom_command(TARGET ${target} POST_BUILD
       COMMAND ${QT5_WINDEPLOYQT_EXECUTABLE} --qmldir ${CMAKE_SOURCE_DIR} $<TARGET_FILE_DIR:${target}>)
endif(WIN32)
