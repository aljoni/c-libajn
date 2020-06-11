cmake_minimum_required(VERSION 3.6)
project(ajn)
add_library(ajn STATIC
    src/list.c)
target_include_directories(ajn PUBLIC include)

