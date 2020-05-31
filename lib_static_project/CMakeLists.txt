cmake_minimum_required(VERSION 3.10.0)

project(template_static_lib VERSION 1.0.0
                            HOMEPAGE_URL https://blog.csdn.net/Chris_Tsai)

option(USE_SHARED "compile shared library or not" on)

add_library(OBJ_FILES OBJECT ${PROJECT_SOURCE_DIR}/src/static_func.cpp)
target_compile_features(OBJ_FILES PRIVATE cxx_std_11)
target_sources(OBJ_FILES PRIVATE ${PROJECT_SOURCE_DIR}/src/func2.cpp)

target_include_directories(OBJ_FILES
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include
)

add_library(${PROJECT_NAME}_static STATIC $<TARGET_OBJECTS:OBJ_FILES>)
set_target_properties(${PROJECT_NAME}_static
    PROPERTIES
    OUTPUT_NAME "lib_static_project"
    CLEAN_DIRECT_OUTPUT 1
    INTERFACE_INCLUDE_DIRECTORIES "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/output/include>"
)

if (USE_SHARED)
    add_library(${PROJECT_NAME}_dynamic SHARED $<TARGET_OBJECTS:OBJ_FILES>)
    set_target_properties(${PROJECT_NAME}_dynamic
        PROPERTIES
        OUTPUT_NAME "lib_static_project"
        CLEAN_DIRECT_OUTPUT 1
        INTERFACE_INCLUDE_DIRECTORIES "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/output/include>"
    )
endif()
