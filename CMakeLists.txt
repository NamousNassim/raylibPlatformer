cmake_minimum_required(VERSION 3.10.0)
project(raylibPlatformer VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# raylib installed at C:/raylib. Build it from source with our own compiler
# so it always matches the compiler used for the game.
set(RAYLIB_DIR "C:/raylib/raylib" CACHE PATH "Path to raylib source")
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(BUILD_GAMES OFF CACHE BOOL "" FORCE)
add_subdirectory(${RAYLIB_DIR} ${CMAKE_BINARY_DIR}/raylib)

# Game sources: src/main.cpp is the entry point. Every .cpp in src/ is compiled.
# CONFIGURE_DEPENDS makes CMake notice new .cpp files without a manual re-configure.
file(GLOB_RECURSE GAME_SOURCES CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/src/*.cpp")

add_executable(raylibPlatformer ${GAME_SOURCES})

# Headers live in include/, so you can write #include "Player.h"
target_include_directories(raylibPlatformer PRIVATE "${CMAKE_SOURCE_DIR}/include")

target_link_libraries(raylibPlatformer PRIVATE raylib)

# Copy assets/ next to the .exe after every build,
# so the game can load files like "assets/textures/player.png".
add_custom_command(TARGET raylibPlatformer POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            "${CMAKE_SOURCE_DIR}/assets"
            "$<TARGET_FILE_DIR:raylibPlatformer>/assets"
)
