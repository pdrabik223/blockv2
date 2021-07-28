cmake_minimum_required(VERSION 3.19)
project(block_v2)

set(CMAKE_CXX_STANDARD 14)

add_executable(block_v2_test
        test.cpp)

add_subdirectory(glfw)
add_subdirectory(glfw_window)
#
target_include_directories(block_v2_test PUBLIC ${PROJECT_SOURCE_DIR}/glfw/include)
#
target_link_directories(block_v2_test PUBLIC glfw/src)

target_link_libraries(block_v2_test
        glfw_window
        glfw)



#
#target_link_libraries(glfw_window glfw)

