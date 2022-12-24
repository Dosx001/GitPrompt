cmake_minimum_required(VERSION 3.16.3)
project(gitprompt VERSION 1.0.0)

set(CMAKE_CXX_FLAGS "-pthread -O1")

add_library(
    lib
    src/Git.cpp
    src/Git.hpp
    )
target_include_directories(lib PUBLIC include)

file(MAKE_DIRECTORY bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} lib)
target_precompile_headers(${PROJECT_NAME} PUBLIC src/pch.hpp)
