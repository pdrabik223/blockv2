cmake_minimum_required(VERSION 3.19)
project(utility)

set(CMAKE_CXX_STANDARD 14)



add_library(utility
        coord.h coord.cpp
        transposition.cpp transposition.h
        rect.cpp rect.h
        )
