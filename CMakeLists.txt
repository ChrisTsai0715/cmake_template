cmake_minimum_required(VERSION 3.10.0)

project(cmake_template VERSION 1.0.0
                       HOMEPAGE_URL https://blog.csdn.net/Chris_Tsai)

#target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_11)

add_subdirectory(lib_static_project)
add_subdirectory(bin_project)

