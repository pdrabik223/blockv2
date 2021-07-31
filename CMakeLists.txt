cmake_minimum_required(VERSION 3.19)
project(block_v2)

set(CMAKE_CXX_STANDARD 14)


add_executable(block_v2_test  test.cpp
        game.cpp game.h
        )

add_subdirectory(sfml)
add_subdirectory(bots)
add_subdirectory(utility)
add_subdirectory(sfml_window)

target_include_directories(block_v2_test
        PUBLIC ${PROJECT_SOURCE_DIR}/sfml/include
        PUBLIC ${PROJECT_SOURCE_DIR}/bots
        PUBLIC ${PROJECT_SOURCE_DIR}/utility
        PUBLIC ${PROJECT_SOURCE_DIR}/sfml_window
        )

target_link_directories(block_v2_test
        PUBLIC sfml/src
        PUBLIC bots
        PUBLIC utility
        PUBLIC sfml_window)

target_link_libraries(block_v2_test
        sfml-graphics
        sfml-system
        sfml-window
        bot
        utility
        sfml_window)



