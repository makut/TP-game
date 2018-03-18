cmake_minimum_required(VERSION 3.5)
project(TP-game)
set(SOURCE_FILES game/Game.h game/Objects.h game/Objects.h game/Objects.cpp game/Unit.h game/Unit.cpp 
    game/RankBuilder.h game/RankBuilder.cpp game/AbstractRace.h game/AbstractRace.cpp
    game/AbstractRaceBuilder.h game/AbstractRaceBuilder.cpp game/Characters.h game/Characters.cpp
    game/Factory.h game/Factory.cpp)
set(TEST_SOURCES test/unit_creation_test.h test/test.cpp ${SOURCE_FILES})
add_executable(Test ${TEST_SOURCES})
target_include_directories(Test PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(Test gtest)
target_link_libraries(Test pthread)
