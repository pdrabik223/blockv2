
add_library(utility
        coord.h coord.cpp
        transposition.cpp transposition.h
        rect.cpp rect.h
        gui_color.cpp gui_color.h)


target_include_directories(utility
        PUBLIC ${PROJECT_SOURCE_DIR}/sfml/include
)

target_link_directories(utility
        PUBLIC sfml/src
)

target_link_libraries(utility
        sfml-graphics
        sfml-system
        sfml-window)