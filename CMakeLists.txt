cmake_minimum_required(VERSION 3.17)
project(matrix_lib)

set(CMAKE_CXX_STANDARD 20)

add_executable(matrix_lib main.cpp include/matrix/matrix.cpp include/matrix/matrix.h)