cmake_minimum_required(VERSION 3.18)
project(9)

set(CMAKE_CXX_STANDARD 23)

set(CMAKE_CXX_FLAGS "-fsanitize=leak,undefined,address")

add_executable(9_1 src/9_1.cpp)
