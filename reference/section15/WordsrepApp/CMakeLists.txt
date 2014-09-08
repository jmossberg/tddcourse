#Set minimum CMake version required to run this file
cmake_minimum_required(VERSION 2.8)

#Set name of project 
project("WordsRepAppProj")

#Set compiler flags:
#  std=c+11 <-- Add support for C++11 features
#  g3 <-- Include debugging information in build
#  Wall <-- Enable all compiler warnings messages
add_definitions(-Wall -g3 -std=c++11)

#Add the given directories to those the compiler uses to search for include files
#  CMAKE_CURRENT_SOURCE_DIR <-- This is the directory where the currently processed CMakeLists.txt is located in 
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/interface)

#Add a subdirectory to the build. The directory specified must contain a CMakeLists.txt file.
add_subdirectory(test)
add_subdirectory(src)

#The add_executable command tells CMake to create a binary
#The first argument is the name of the binary to create, the
#rest are source files. Header files are not included in this
#command. 
add_executable(wordsrepapp ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)

#target_link_libraries specifies libraries or flags to use 
#when linking a given target. The named target (first 
#argument) must have been created in the current directory
#with add_executable() or add_library()
target_link_libraries(wordsrepapp src)
