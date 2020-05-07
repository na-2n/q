cmake_minimum_required(VERSION 3.1)

project("Qengine")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)

add_subdirectory("third_party")
add_subdirectory("src")
