cmake_minimum_required(VERSION 3.2)
project(my_clock)

set(CMAKE_C_FLAGS "-std=c99")

find_package (Threads REQUIRED)
find_package(Curses REQUIRED)

link_libraries(ncurses pthread)

include_directories( ${CURSES_INCLUDE_DIR} )

set(SOURCE_FILES
    clock.c
    myui_thread.c
    myui_thread.h
    time_utils.c
    time_utils.h)

#get_cmake_property(_variableNames VARIABLES)
#foreach (_variableName ${_variableNames})
#    message(STATUS "${_variableName}=${${_variableName}}")
#endforeach()

add_executable(my_clock ${SOURCE_FILES})