cmake_minimum_required(VERSION 3.18)
project(11)

set(CMAKE_CXX_STANDARD 23)

set(CMAKE_CXX_FLAGS "-fsanitize=leak,undefined,address")

add_executable(11_1 src/1.cpp)
