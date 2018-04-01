cmake_minimum_required(VERSION 3.5)
project(TP-game)

set(CMAKE_BUILD_TYPE Release)
if("${DEBUG}" STREQUAL "ON")
    set(CMAKE_BUILD_TYPE Debug)
endif()

file(GLOB SOURCE_FILES game/*.cpp game/*.h)

if("${WITH_TEST}" STREQUAL "ON")
    file(GLOB TEST_SOURCES test/*.h test/*.cpp ${SOURCE_FILES})
    add_executable(UnitTest ${TEST_SOURCES})
    target_include_directories(UnitTest PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
    target_link_libraries(UnitTest gtest)
    target_link_libraries(UnitTest pthread)
add_test(UnitTest UnitTest)
endif()

