add_library(bot
        bot.h bot.cpp
        empty.h empty.cpp
        basic.cpp basic.h
        bedrock.cpp bedrock.h
        turn.cpp turn.h
        goal.cpp goal.h
        enemy.cpp enemy.h
        engine.cpp engine.h
        factory.cpp factory.h
        bots_include.h)

target_include_directories(bot
        PRIVATE ${PROJECT_SOURCE_DIR}/utility)

target_link_directories(bot PRIVATE utility)

target_link_libraries(bot
        utility)