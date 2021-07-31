add_library(sfml_window
        window.cpp window.h
        context.cpp context.h
        )


#add_subdirectory(../sfml)
target_include_directories(sfml_window
        PUBLIC ${PROJECT_SOURCE_DIR}/sfml/include
        PUBLIC ${PROJECT_SOURCE_DIR}/utility)

target_link_directories(sfml_window
        PUBLIC sfml/src
        PUBLIC utility)

target_link_libraries(sfml_window
        sfml-graphics
        sfml-system
        sfml-window
        utility)