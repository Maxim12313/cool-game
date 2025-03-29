cmake_minimum_required(VERSION 3.22)
project(CoolGame)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED true)

include_directories(include)

# all cpp files in src excluding main
file(GLOB SOURCE_FILES "${CMAKE_SOURCE_DIR}/src/*.cpp")
list(REMOVE_ITEM SOURCE_FILES "${CMAKE_SOURCE_DIR}/src/main.cpp")

message(STATUS "Source files: ${SOURCE_FILES}")


add_executable(app.exe src/main.cpp ${SOURCE_FILES})
add_executable(game_tests.exe tests/main.cpp ${SOURCE_FILES})

find_package(SDL2 REQUIRED CONFIG REQUIRED COMPONENTS SDL2)
find_package(SDL2 REQUIRED CONFIG COMPONENTS SDL2main)

# Link to the actual SDL2 library. SDL2::SDL2 is the shared SDL library, SDL2::SDL2-static is the static SDL libarary.
target_link_libraries(app.exe PRIVATE SDL2::SDL2)
target_link_libraries(game_tests.exe PRIVATE SDL2::SDL2)


