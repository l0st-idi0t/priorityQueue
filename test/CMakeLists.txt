cmake_minimum_required(3.8)

set(This priorityQueueTests)

set(Sources
    tests.cpp
)

add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC
    gtest_main
    priorityQueue
)

add_test(
    NAME ${This}
    COMMAND ${This}
)

