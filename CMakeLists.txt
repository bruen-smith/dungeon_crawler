cmake_minimum_required(VERSION 3.28)
project(dungeon_crawler LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(libtcod CONFIG REQUIRED)

add_executable(dungeon_crawler main.cpp)
target_link_libraries(dungeon_crawler PRIVATE libtcod::libtcod)
