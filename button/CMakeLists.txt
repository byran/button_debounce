cmake_minimum_required(VERSION 3.3)
project(button)

set(SOURCE_FILES
        button.c)

set(HEADER_FILES
        button.h timer.h io_pins.h)

add_library(button ${SOURCE_FILES} ${HEADER_FILES})