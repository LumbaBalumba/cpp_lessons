cmake_minimum_required(VERSION 3.26)
project(pluses)

set(CMAKE_CXX_FLAGS, "-O2 -Wall -Werror -Wpedantic -m64 -fsanitize=leak,undefined,address")

add_executable(1 1/1.cpp)
add_executable(2 2/2.cpp)
add_executable(3 3/3.cpp)
add_executable(4 4/4.cpp)
add_executable(5 5/5.cpp)
add_executable(6 6/6.cpp)
add_executable(7 7/7.cpp)
