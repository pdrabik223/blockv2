add_library(sfml_window
        window.cpp window.h
        context/context.cpp context/context.h
        context/main_menu.cpp context/main_menu.h
        window_utility/button.cpp window_utility/button.h
        window_utility/text_button.cpp window_utility/text_button.h
        window_utility/text_box.cpp window_utility/text_box.h
        context/run_simulation.cpp context/run_simulation.h
        context/level_creator.cpp context/level_creator.h
        context/level_player.cpp context/level_player.h
        context/level_picker.cpp context/level_picker.h)


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