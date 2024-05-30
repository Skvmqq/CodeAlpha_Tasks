cmake_minimum_required(VERSION 3.26)
project(sudukuSolver)

set(CMAKE_CXX_STANDARD 17)

add_executable(sudukuSolver main.cpp
        Sudoku.cpp
        Sudoku.h)
