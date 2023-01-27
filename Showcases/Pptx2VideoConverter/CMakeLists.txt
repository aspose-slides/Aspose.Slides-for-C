cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(Pptx2VideoConverter LANGUAGES CXX)

set(target "${PROJECT_NAME}")

find_package(CodePorting.Translator.Cs2Cpp.Framework REQUIRED CONFIG PATHS $ENV{ASPOSE_SLIDES_CPP_PATH}/CodePorting.Translator.Cs2Cpp.Framework NO_DEFAULT_PATH)
find_package(Aspose.Slides.Cpp REQUIRED CONFIG PATHS $ENV{ASPOSE_SLIDES_CPP_PATH}/Aspose.Slides.Cpp NO_DEFAULT_PATH)

file(TO_NATIVE_PATH "${CodePorting.Translator.Cs2Cpp.Framework_DIR}/lib" CodePorting.Translator.Cs2Cpp.Framework_DLL_PATH)
file(TO_NATIVE_PATH "${Aspose.Slides.Cpp_DIR}/lib" Aspose.Slides.Cpp_DLL_PATH)

if (MSVC AND ${CMAKE_VERSION} VERSION_LESS "3.13.5")
    message (WARNING "You must manually set the Debugging Environment to PATH=${Aspose.Slides.Cpp_DLL_PATH};${CodePorting.Translator.Cs2Cpp.Framework_DLL_PATH};%PATH% to run the examples")
endif()

file(GLOB_RECURSE srcs "sources/*.cpp")
file(GLOB_RECURSE hdrs "sources/*.h")

add_executable(${target} ${srcs} ${hdrs})

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${target})

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
    VS_DEBUGGER_ENVIRONMENT "PATH=${Aspose.Slides.Cpp_DLL_PATH};${CodePorting.Translator.Cs2Cpp.Framework_DLL_PATH};%PATH%"
)

target_include_directories(${target} PRIVATE "sources")

target_link_libraries(${PROJECT_NAME} PRIVATE Aspose.Slides.Cpp)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Aspose::CodePorting.Translator.Cs2Cpp.Framework> $<TARGET_FILE_DIR:${PROJECT_NAME}>
    COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Aspose.Slides.Cpp> $<TARGET_FILE_DIR:${PROJECT_NAME}>
)
