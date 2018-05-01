cmake_minimum_required(VERSION 3.10)
project(RationalNumber)

set(CMAKE_CXX_STANDARD 17)

find_package(Threads REQUIRED)

#-------------------
# `User` program
#-------------------

file(GLOB SRC_FILES
        main.cpp
        Rational.*
        Exceptions.h)
add_executable(RationalNumber ${SRC_FILES})


#-------------------
# Test
#-------------------
enable_testing()
include_directories(${COMMON_INCLUDES})

file(GLOB TEST_SRC_FILES ${PROJECT_SOURCE_DIR}/test/src/*.cpp Rational.*)

add_executable(runAllTests ${TEST_SRC_FILES})
target_link_libraries(runAllTests gtest gtest_main ${CMAKE_THREAD_LIBS_INIT})
