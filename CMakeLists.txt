cmake_minimum_required(VERSION 3.22)
project(CoolGame)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED true)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wshadow -Wno-sign-compare -Wfloat-equal -fsanitize=undefined")

include_directories(include)

# all cpp files in src excluding main
file(GLOB SOURCE_FILES "${CMAKE_SOURCE_DIR}/src/*.cpp")
list(REMOVE_ITEM SOURCE_FILES "${CMAKE_SOURCE_DIR}/src/main.cpp")

message(STATUS "Source files: ${SOURCE_FILES}")

add_executable(app.exe src/main.cpp ${SOURCE_FILES})
add_executable(game_tests.exe tests/main.cpp ${SOURCE_FILES})

find_package(SDL3 REQUIRED CONFIG COMPONENTS SDL3)

target_link_libraries(app.exe PRIVATE SDL3::SDL3)
target_link_libraries(game_tests.exe PRIVATE SDL3::SDL3)

target_include_directories(game_tests.exe PRIVATE ${CMAKE_SOURCE_DIR}/tests)
