# 'Google_test' is the subproject name
cmake_minimum_required(VERSION 3.19)
project(google_tests)

set(CMAKE_CXX_STANDARD 14)

add_executable(google_tests transposition_class_tests.cpp)

#add_subdirectory(../googletest)

target_include_directories(google_tests
        PUBLIC ${PROJECT_SOURCE_DIR}/googletest/googletest/include
        PUBLIC ${PROJECT_SOURCE_DIR}/bots
        PUBLIC ${PROJECT_SOURCE_DIR}/utility
        )
target_link_directories(google_tests
        PUBLIC utility
        PUBLIC bot
        )

target_link_libraries(google_tests
        gtest
        gtest_main
        bot
        utility
        )


add_test(NAME google_tests
        COMMAND google_tests)
