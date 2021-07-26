cmake_minimum_required(VERSION 3.19)
project(blockv2)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(SFML)
include_directories( ${PROJECT_SOURCE_DIR}/sfml/include)

add_executable(blockv2
        test.cpp)

find_library(SFML REQUIRED PATHS ${PROJECT_SOURCE_DIR}/bin/)
target_link_libraries(admin_gui ${SFML})