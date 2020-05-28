cmake_minimum_required(VERSION 3.10.0)

project(template_static_lib VERSION 1.0.0
    HOMEPAGE_URL https://blog.csdn.net/Chris_Tsai)

add_library(${PROJECT_NAME} STATIC ${PROJECT_SOURCE_DIR}/src/static_func.cpp)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_11)

target_sources(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/src/func2.cpp)

target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include
    PUBLIC
        "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/output/include>"
)

set_target_properties(${PROJECT_NAME}
    PROPERTIES
    OUTPUT_NAME "lib_static_project"
)
