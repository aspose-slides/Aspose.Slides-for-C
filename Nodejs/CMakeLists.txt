cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(Aspose.Slides.Cpp.Nodejs.Addon CXX)

set(target "${PROJECT_NAME}")

message (STATUS ${ASPOSE_SLIDES_PATH})

if(DEFINED ASPOSE_SLIDES_PATH)
    message(STATUS "Using ASPOSE_SLIDES_PATH value: ${ASPOSE_SLIDES_PATH}")
else()
    message(FATAL_ERROR "ASPOSE_SLIDES_PATH not set")
endif()

include_directories(${CMAKE_JS_INC})

set(SOURCE_FILES "src/AsposeSlidesCppAddon.cpp")

add_library(${target} SHARED ${SOURCE_FILES} ${CMAKE_JS_SRC})

set_target_properties(${target} PROPERTIES PREFIX "" SUFFIX ".node")

find_package(CodePorting.Translator.Cs2Cpp.Framework REQUIRED CONFIG PATHS ${ASPOSE_SLIDES_PATH} NO_DEFAULT_PATH)
find_package(Aspose.Slides.Cpp REQUIRED CONFIG PATHS ${ASPOSE_SLIDES_PATH} NO_DEFAULT_PATH)

file(TO_NATIVE_PATH "${Aspose.Slides.Cpp_DIR}/lib" Aspose.Slides.Cpp_DLL_PATH)
file(TO_NATIVE_PATH "${CodePorting.Translator.Cs2Cpp.Framework_DIR}/lib" CodePorting.Translator.Cs2Cpp.Framework_DLL_PATH)

if (MSVC AND ${CMAKE_VERSION} VERSION_LESS "3.13.5")
    message (WARNING "You must menually set the Debugging Environment to PATH=${Aspose.Slides.Cpp_DLL_PATH};${CodePorting.Translator.Cs2Cpp.Framework_DLL_PATH};%PATH% to run the examples")
endif()

target_link_libraries(${target} PRIVATE ${CMAKE_JS_LIB})
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

# Include N-API wrappers
execute_process(COMMAND node -p "require('node-addon-api').include"
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        OUTPUT_VARIABLE NODE_ADDON_API_DIR
        )
string(REPLACE "\n" "" NODE_ADDON_API_DIR ${NODE_ADDON_API_DIR})
string(REPLACE "\"" "" NODE_ADDON_API_DIR ${NODE_ADDON_API_DIR})
target_include_directories(${PROJECT_NAME} PRIVATE ${NODE_ADDON_API_DIR})
add_definitions(-DNAPI_VERSION=3)
