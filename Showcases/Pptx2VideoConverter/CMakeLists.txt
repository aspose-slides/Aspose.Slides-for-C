cmake_minimum_required(VERSION 3.5)

project(Pptx2VideoConverter LANGUAGES CXX)

set(APP_VERSION "1.0")

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(CodePorting.Translator.Cs2Cpp.Framework REQUIRED)
find_package(Aspose.Slides.Cpp REQUIRED)

set(PROJECT_SOURCES
    main.cpp
    pptx2video_converter.cpp
    pptx2video_converter.h
    command_line_options.h
)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})

target_compile_definitions(${PROJECT_NAME} PUBLIC "APP_VERSION=\"${APP_VERSION}\"")

target_link_libraries(${PROJECT_NAME} PRIVATE Aspose.Slides.Cpp)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Aspose::CodePorting.Translator.Cs2Cpp.Framework> $<TARGET_FILE_DIR:${PROJECT_NAME}>
    COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Aspose.Slides.Cpp> $<TARGET_FILE_DIR:${PROJECT_NAME}>
)
