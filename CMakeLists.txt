cmake_minimum_required(VERSION 3.31)
project(GameEngine)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED true)

include_directories(include)

# all cpp files in src excluding main
file(GLOB SOURCE_FILES "src/*.cpp")
list(REMOVE_ITEM SOURCE_FILES "${CMAKE_SOURCE_DIR}/src/main.cpp")

add_executable(game_engine.exe src/main.cpp ${SOURCE_FILES})
add_executable(all_tests.exe tests/main.cpp ${SOURCE_FILES})
