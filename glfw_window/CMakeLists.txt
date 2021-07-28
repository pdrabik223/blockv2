
add_library(glfw_window
        window.h window.cpp)

target_include_directories(glfw_window PUBLIC ${PROJECT_SOURCE_DIR}/glfw/include)

target_link_directories(glfw_window PUBLIC ../glfw/src)

target_link_libraries(glfw_window glfw)
