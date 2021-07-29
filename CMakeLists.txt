cmake_minimum_required(VERSION 3.19)
project(block_v2)

set(CMAKE_CXX_STANDARD 14)

#set(GLFW_WINDOW
#        glfw_window/window.h glfw_window/window.cpp
#        glfw_window/button.h glfw_window/button.cpp
#        glfw_window/load_bmp.cpp)

set(SFML_WINDOW
        sfml_window/window.h sfml_window/window.cpp)

add_executable(block_v2_test
        test.cpp
        ${SFML_WINDOW}
        )

add_subdirectory(sfml)
add_subdirectory(bots)
add_subdirectory(utility)

target_include_directories(block_v2_test
        PUBLIC ${PROJECT_SOURCE_DIR}/sfml/include
        PUBLIC ${PROJECT_SOURCE_DIR}/bots
        PUBLIC ${PROJECT_SOURCE_DIR}/utility
        )

target_link_directories(block_v2_test
        PUBLIC sfml/src
        PUBLIC bots
        PUBLIC utility)

target_link_libraries(block_v2_test
        sfml-graphics
        sfml-system
        sfml-window
        bot
        utility
        )



