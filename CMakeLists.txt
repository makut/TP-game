cmake_minimum_required(VERSION 3.5)
project(TP-game)

set(CMAKE_BUILD_TYPE Release)
if("${DEBUG}" STREQUAL "ON")
    set(CMAKE_BUILD_TYPE Debug)
endif()

set(SOURCE_FILES game/Game.h game/Objects.h game/Objects.h game/Objects.cpp game/Unit.h game/Unit.cpp 
    game/RankBuilder.h game/RankBuilder.cpp game/AbstractRace.h game/AbstractRace.cpp
    game/AbstractRaceBuilder.h game/AbstractRaceBuilder.cpp game/Characters.h game/Characters.cpp
    game/Factory.h game/Factory.cpp)

if("${WITH_TEST}" STREQUAL "ON")
    set(TEST_SOURCES test/unit_creation_test.h test/test.cpp ${SOURCE_FILES})
    add_executable(UnitTest ${TEST_SOURCES})
    target_include_directories(UnitTest PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
    target_link_libraries(UnitTest gtest)
    target_link_libraries(UnitTest pthread)
add_test(UnitTest UnitTest)
endif()

