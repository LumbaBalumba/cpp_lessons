cmake_minimum_required(VERSION 3.18)
project(7)

set(CMAKE_CXX_STANDARD 23)

set(CMAKE_CXX_FLAGS "-fsanitize=leak,undefined,address")

add_executable(7_1 src/7_1.cpp)
add_executable(7_2 src/7_2.cpp src/func.cpp)

target_include_directories(7_2 PUBLIC include)

add_executable(7_3 src/7_3.cpp)
add_executable(7_4 src/7_4.cpp)
