add_library(context
        context_include.h
        context.cpp context.h
        main_menu.cpp main_menu.h
        run_simulation.cpp run_simulation.h
        level_creator.cpp level_creator.h
        level_player.cpp level_player.h
        level_picker.cpp level_picker.h creator_input_panel.cpp creator_input_panel.h)

target_include_directories(context
        PUBLIC ${PROJECT_SOURCE_DIR}/sfml/include
        PUBLIC ${PROJECT_SOURCE_DIR}/utility
        PUBLIC ${PROJECT_SOURCE_DIR}/sfml_window/window_utility
        PUBLIC ${PROJECT_SOURCE_DIR}/bots)

target_link_directories(context
        PUBLIC sfml/src
        PUBLIC utility
        PUBLIC sfml_window/window_utility
        PUBLIC bot)

target_link_libraries(context
        sfml-graphics
        sfml-system
        sfml-window
        utility
        window_utility
        bot)