cmake_minimum_required(VERSION 3.2)
project(samples_ncurses)

set(CMAKE_C_FLAGS "-std=c99")

find_package (Threads REQUIRED)
find_package(Curses REQUIRED)

link_libraries(ncurses pthread)

include_directories( ${CURSES_INCLUDE_DIR} )

set(SOURCE_FILES
    curhello.c
    ncurses_thread.c
    ncurses_thread.h
    time_utils.c
    time_utils.h)

add_executable(samples_ncurses ${SOURCE_FILES})