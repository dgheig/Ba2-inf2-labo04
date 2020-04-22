cmake_minimum_required(VERSION 3.15)
project(Ba2-labo03)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wconversion -Wall -Wextra -pedantic -std=c++11")


file(MAKE_DIRECTORY builds)
# https://cmake.org/cmake/help/latest/variable/CMAKE_SOURCE_DIR.html#variable:CMAKE_SOURCE_DIR
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

if(DEBUG)
    add_definitions(-DDEBUG)
endif()

add_executable(
    labo_04_carvalho_bruno_gallay_david
    labo_04_carvalho_bruno_gallay_david.cpp
    src/temps.ipp src/temps.h
)

# add_executable(testDiffDate tests/testDiffDate.cpp src/date.cpp src/date.h)
