cmake_minimum_required(VERSION 3.0)
project(raylib_template CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Setting parameters for raylib
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
set(BUILD_GAMES    OFF CACHE BOOL "" FORCE) # or games

#add_subdirectory(code)
include_directories(${PROJECT_SOURCE_DIR})

add_executable(game src/main.cpp src/character.cpp src/prop.cpp src/enemy.cpp src/basecharacter.cpp)
target_link_libraries(game raylib)
target_compile_definitions(game PUBLIC ASSETS_PATH="${CMAKE_CURRENT_SOURCE_DIR}/assets/") # Set the asset path macro to the absolute path on the dev machine
#target_compile_definitions(raylib_template PUBLIC ASSETS_PATH="relative-path-to-assets-in-the-game-package") # Set the asset path macro in release more
