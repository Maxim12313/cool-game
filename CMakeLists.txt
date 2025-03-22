cmake_minimum_required(VERSION 3.31)
project(GameEngine)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED true)

add_executable(game_engine.exe src/main.cpp)
add_executable(all_tests.exe tests/main.cpp)
