cmake_minimum_required(VERSION 3.19)
project(block_v2)

set(CMAKE_CXX_STANDARD 14)

set(GLFW_WINDOW
        glfw_window/window.h  glfw_window/window.cpp
        glfw_window/button.h glfw_window/button.cpp
        glfw_window/load_bmp.cpp)

add_executable(block_v2_test
        test.cpp
        ${GLFW_WINDOW})

add_subdirectory(glfw)
#add_subdirectory(glfw_window) I trued to do it proper way, but I can't

target_include_directories(block_v2_test PUBLIC ${PROJECT_SOURCE_DIR}/glfw/include)
target_link_directories(block_v2_test PUBLIC glfw/src)

add_subdirectory(sfml)

target_include_directories(block_v2_test PUBLIC ${PROJECT_SOURCE_DIR}/sfml/include)
target_link_directories(block_v2_test PUBLIC sfml/src)

target_link_libraries(block_v2_test
        #glfw_window
        sfml-graphics
        sfml-system
        sfml-window
        glfw
        )



