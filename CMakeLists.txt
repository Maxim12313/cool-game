cmake_minimum_required(VERSION 3.31)
project(GameEngine)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED true)

set(SOURCE_FILES src/cool.cpp)
add_executable(game_engine.exe src/main.cpp ${SOURCE_FILES})
add_executable(all_tests.exe tests/main.cpp ${SOURCE_FILES})

include_directories(include)
