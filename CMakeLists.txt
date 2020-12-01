cmake_minimum_required(VERSION 3.17)
project(matrix_lib)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)
include_directories(include/matrix)
include_directories(include/validate)

add_executable(matrix_lib
        include/matrix/matrix.cpp
        include/matrix/matrix.h
        include/validate/validate.h
        main.cpp
        )
