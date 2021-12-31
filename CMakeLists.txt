cmake_minimum_required(VERSION 3.20)
project(di0des VERSION 0.1.0 LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_compile_options(-Wall -g)

add_executable(di0des src/main.c)
