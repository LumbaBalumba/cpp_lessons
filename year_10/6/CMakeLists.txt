cmake_minimum_required(VERSION 3.18)
project(3)

set(CMAKE_CXX_STANDARD 23)

set(CMAKE_CXX_FLAGS "-fsanitize=leak,undefined,address")

add_executable(6_1 src/6_1.cpp src/6_2.cpp)
target_include_directories(6_1 PUBLIC include)

add_executable(6_3 src/6_3.cpp)
