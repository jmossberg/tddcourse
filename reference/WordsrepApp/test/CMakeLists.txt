set(GMOCK_DIR "../google/gmock-1.7.0"
    CACHE PATH "The path to the GoogleMock test framework.")

add_subdirectory(${GMOCK_DIR} {CMAKE_BINARY_DIR}/gmock)

include_directories(SYSTEM ${GMOCK_DIR}/gtest/include
                           ${GMOCK_DIR}/include)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/mock)
include_directories(${CMAKE_SOURCE_DIR}/test)

add_executable(main.cpp ArgumentParserClassTest.cpp LineToWordsClassTest.cpp WordsrepClassTest.cpp WordsToLineClassTest.cpp)

target_link_libraries(wordsrepapptest gmock_main)
target_link_libraries(wordsrepapptest src)

add_test(wordsrepapptest wordsrepapptest)
