cmake_minimum_required(VERSION 3.31)
project(AlgsT1)

set(CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

add_executable(AlgsT1 src/main.cpp
        src/algoritmos.cpp
        src/algoritmos.h
)
