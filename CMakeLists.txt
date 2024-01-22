cmake_minimum_required(VERSION 3.26)
project(pluses)

set(CMAKE_CXX_FLAGS, "-O2 -Wall -Werror -Wpedantic -m64 -fsanitize=leak,undefined,address")

add_executable(main 1/1.cpp)
