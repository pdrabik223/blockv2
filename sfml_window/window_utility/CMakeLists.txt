add_library(window_utility
        button.cpp button.h
        text_button.cpp text_button.h
        text_box.cpp text_box.h
        image_button.h  image_button.cpp)


target_include_directories(window_utility
        PUBLIC ${PROJECT_SOURCE_DIR}/sfml/include
        PUBLIC ${PROJECT_SOURCE_DIR}/utility)

target_link_directories(window_utility
        PUBLIC sfml/src
        PUBLIC utility)

target_link_libraries(window_utility
        sfml-graphics
        sfml-system
        sfml-window
        utility)