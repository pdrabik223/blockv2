add_library(sfml_window
        window.cpp window.h
    )


#add_subdirectory(../sfml)
target_include_directories(sfml_window
        PUBLIC ${PROJECT_SOURCE_DIR}/sfml/include
        PUBLIC ${PROJECT_SOURCE_DIR}/utility
        PUBLIC ${PROJECT_SOURCE_DIR}/sfml_window/context)

target_link_directories(sfml_window
        PUBLIC sfml/src
        PUBLIC utility
        PUBLIC sfml_window/context/context)

target_link_libraries(sfml_window
        sfml-graphics
        sfml-system
        sfml-window
        utility
        context)