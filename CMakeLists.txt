cmake_minimum_required(VERSION 3.19)
project(block_v2)

set(CMAKE_CXX_STANDARD 14)

add_executable(block_v2_test
        test.cpp)

add_subdirectory(sfml)

target_include_directories(block_v2_test PUBLIC ${PROJECT_SOURCE_DIR}/sfml/include)

target_link_directories(block_v2_test PUBLIC /sfml/src)

target_link_libraries(block_v2_test sfml-graphics sfml-window)


