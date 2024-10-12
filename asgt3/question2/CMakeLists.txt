cmake_minimum_required(VERSION 3.25)
project(q2 C)

set(CMAKE_C_STANDARD 11)

add_executable(q2 question2.c)
target_link_libraries(q2 m)