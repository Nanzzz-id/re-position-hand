cmake_minimum_required(VERSION 3.10.2)
project("LeviViewModel")

# Hanya kompilasi file main.cpp saja untuk tes awal
add_library(LeviViewModel SHARED src/main.cpp)

target_link_libraries(LeviViewModel
    android
    log
)
