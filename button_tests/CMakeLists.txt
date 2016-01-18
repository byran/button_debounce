project(button_tests)

include(${gtest_SOURCE_DIR}/cmake/internal_utils.cmake)
config_compiler_and_linker()

include_directories("${gmock_SOURCE_DIR}/include"
        "${gtest_SOURCE_DIR}/include"
        "${button_SOURCE_DIR}")

set(SOURCE_FILES
        button.tests.cpp)

add_executable(button_tests ${SOURCE_FILES})
target_link_libraries(button_tests gmock_main button)