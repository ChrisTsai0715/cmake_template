cmake_minimum_required(VERSION 3.10.0)

project(cmake_template VERSION 1.0.0
                       HOMEPAGE_URL https://blog.csdn.net/Chris_Tsai)

add_executable(${PROJECT_NAME} src/main.cpp)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_11)

add_subdirectory(lib_static_project)

target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${CMAKE_SOURCE_DIR}/include
)

target_sources(
    ${PROJECT_NAME}
    PRIVATE
        src/func.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE lib_static_project)

