cmake_minimum_required(VERSION 2.8)

project("WordsRepAppProj")

add_definitions(-Wall -g3 -std=c++11)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/interface)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

add_subdirectory(src)
add_subdirectory(test)

add_executable(wordsrepapp ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)
target_link_libraries(wordsrepapp src)
