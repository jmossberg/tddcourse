set(GMOCK_DIR "../google/gmock-1.7.0"
    CACHE PATH "The path to the GoogleMock test framework.")

add_subdirectory(${GMOCK_DIR} {CMAKE_BINARY_DIR}/gmock)

include_directories(SYSTEM ${GMOCK_DIR}/gtest/include
                           ${GMOCK_DIR}/include)

include_directories(${CMAKE_SOURCE_DIR}/test)

add_executable(wordsrepapptest main.cpp DummyTest.cpp)

target_link_libraries(wordsrepapptest gmock_main)