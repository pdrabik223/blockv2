cmake_minimum_required(VERSION 3.19)
project(tests)

set(CMAKE_CXX_STANDARD 14)

add_executable(tests transposition_class_tests.cpp)

#add_subdirectory(../googletest)

target_include_directories(tests
        PUBLIC ${PROJECT_SOURCE_DIR}/googletest/googletest/include
        PUBLIC ${PROJECT_SOURCE_DIR}/bots
        PUBLIC ${PROJECT_SOURCE_DIR}/utility
        )
target_link_directories(tests
        PUBLIC utility
        PUBLIC bot
        )

target_link_libraries(tests
        gtest
        gtest_main
        bot
        utility
        )


add_test(NAME google_tests
        COMMAND google_tests)
