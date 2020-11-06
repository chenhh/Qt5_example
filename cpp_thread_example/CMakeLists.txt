cmake_minimum_required(VERSION 3.5)

project(cpp_thread_example LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(thread_object thread_object.cpp)
add_executable(cpp_thread_example2 main2.cpp)
