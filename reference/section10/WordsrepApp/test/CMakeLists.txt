#Set a cache and an environment variable
set(GMOCK_DIR "../google/gmock-1.7.0"
    CACHE PATH "The path to the GoogleMock test framework.")

#Add a subdirectory to the build. The directory specified must contain a CMakeLists.txt file.
#  GMOCK_DIR value has been set with the set command
#  CMAKE_BINARY_DIR <-- The path to the top level of the build tree. That is the directory from where cmake is run.
add_subdirectory(${GMOCK_DIR} {CMAKE_BINARY_DIR}/gmock)

#Add the given directories to those the compiler uses to search for include files
include_directories(SYSTEM ${GMOCK_DIR}/gtest/include
                           ${GMOCK_DIR}/include)

include_directories(${CMAKE_SOURCE_DIR}/test)

#The add_executable command tells CMake to create a binary
#The first argument is the name of the binary to create, the
#rest are source files. Header files are not included in this
#command. 
add_executable(wordsrepapptest main.cpp DummyTest.cpp ArgumentParserClassTest.cpp LineToWordsClassTest.cpp)

#target_link_libraries specifies libraries or flags to use 
#when linking a given target. The named target (first 
#argument) must have been created in the current directory
#with add_executable() or add_library()
target_link_libraries(wordsrepapptest gmock_main)
target_link_libraries(wordsrepapptest src)
