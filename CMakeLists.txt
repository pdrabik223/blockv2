cmake_minimum_required(VERSION 3.19)
project(blockv2)

set(CMAKE_CXX_STANDARD 14)

add_executable(blockv2
        test.cpp)

add_subdirectory(sfml)

target_include_directories(blockv2 PUBLIC ${PROJECT_SOURCE_DIR}/sfml/include)

target_link_directories(blockv2 PRIVATE  /sfml/src)

target_link_libraries(blockv2 sfml-graphics)


