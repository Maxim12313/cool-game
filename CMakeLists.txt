cmake_minimum_required(VERSION 3.22)
project(CoolGame)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED true)

include_directories(include)

# all cpp files in src excluding main
file(GLOB SOURCE_FILES "src/*.cpp")
list(REMOVE_ITEM SOURCE_FILES "${CMAKE_SOURCE_DIR}/src/main.cpp")


add_executable(game.exe src/main.cpp ${SOURCE_FILES})
add_executable(all_tests.exe tests/main.cpp ${SOURCE_FILES})

find_package(glfw3 3.3 REQUIRED)
target_link_libraries(game.exe PRIVATE glfw)
target_link_libraries(all_tests.exe PRIVATE glfw)

add_library(glad STATIC include/glad/glad.h src/glad.c)
target_link_libraries(game.exe PRIVATE glad)
target_link_libraries(all_tests.exe PRIVATE glad)



