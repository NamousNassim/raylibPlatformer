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

add_executable(raylibPlatformer main.cpp)
target_link_libraries(raylibPlatformer PRIVATE raylib)
