cmake_minimum_required(VERSION 3.18)

project(test_project CXX)

set(CMAKE_CXX_STANDARD 20)

add_executable(test src/main.cpp src/func.cpp)
target_include_directories(test PUBLIC include)
target_link_libraries(test fmt)
