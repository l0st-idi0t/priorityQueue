cmake_minimum_required(VERSION 3.8)

set(This priorityQueue)

project(${This} C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

enable_testing()

add_subdirectory(googletest)

set(Headers
    priorityqueue.h
)

set(Sources
    tests.cpp
)

add_library(${This}) STATIC ${Sources} ${Headers}
add_executable(${This} ${Sources})

target_link_libraries(${This} PUBLIC
    gtest_main
    priorityQueue
)

add_test(
    NAME ${This}
    COMMAND ${This}
)

