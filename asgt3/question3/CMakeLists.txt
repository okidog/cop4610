cmake_minimum_required(VERSION 3.25)
project(2.3 C)

set(CMAKE_C_STANDARD 11)

add_executable(2.3 question3.c)
target_link_libraries(2.3 m)