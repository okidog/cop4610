cmake_minimum_required(VERSION 3.25)
project(q3 C)

set(CMAKE_C_STANDARD 11)

add_executable(q3 question3.c)
target_link_libraries(q3 m)