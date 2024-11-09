cmake_minimum_required(VERSION 3.18)
project(3)

set(CMAKE_CXX_STANDARD 23)

set(CMAKE_CXX_FLAGS "-fsanitize=leak,undefined,address")

add_executable(4_1 src/4_1.cpp)
add_executable(4_2 src/4_2.cpp)
add_executable(4_3 src/4_3.cpp)
add_executable(4_4 src/4_4.cpp)
