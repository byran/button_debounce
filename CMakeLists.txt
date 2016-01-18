cmake_minimum_required(VERSION 3.3)
project(button_debounce_root)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_subdirectory(gmock)

# Only turn on extra compiler warning after compiling google mock
# to avoid warnings from code not written by me
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")

add_subdirectory(button)
add_subdirectory(button_tests)