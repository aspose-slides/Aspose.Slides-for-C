cmake_minimum_required(VERSION 3.5)

project(PresentationExplorer LANGUAGES CXX)

set(APP_VERSION "1.0")

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED PATHS ${QT_DIR})

find_package(CodePorting.Translator.Cs2Cpp.Framework REQUIRED)
find_package(Aspose.Slides.Cpp REQUIRED)

set(PROJECT_SOURCES
    main.cpp
    main_window.cpp
    main_window.h
    main_window.ui
    about_dialog.cpp
    about_dialog.h
    about_dialog.ui
    presentation_model.cpp
    presentation_model.h
    presentation_node_list.h
    presentation_node_list.cpp
    hidpisupport.cpp
    hidpisupport.h
    qtcorehelpers.h
    resources.qrc
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})
else()
    add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})
endif()

target_compile_definitions(${PROJECT_NAME} PUBLIC "APP_VERSION=\"${APP_VERSION}\"")
set_property(TARGET ${PROJECT_NAME} PROPERTY WIN32_EXECUTABLE true)

target_link_libraries(${PROJECT_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Aspose.Slides.Cpp)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Aspose::CodePorting.Translator.Cs2Cpp.Framework> $<TARGET_FILE_DIR:${PROJECT_NAME}>
    COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Aspose.Slides.Cpp> $<TARGET_FILE_DIR:${PROJECT_NAME}>
)

if(WIN32)
    get_target_property(QMAKE_EXECUTABLE Qt${QT_VERSION_MAJOR}::qmake IMPORTED_LOCATION)
    get_filename_component(WINDEPLOYQT_EXECUTABLE ${QMAKE_EXECUTABLE} PATH)
    set(WINDEPLOYQT_EXECUTABLE "${WINDEPLOYQT_EXECUTABLE}/windeployqt.exe")

    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
       COMMAND ${WINDEPLOYQT_EXECUTABLE} --no-compiler-runtime $<TARGET_FILE:${PROJECT_NAME}>)
endif()
