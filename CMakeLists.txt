cmake_minimum_required(VERSION 3.10.2)

project("LeviViewModel")

# Include directories
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/include/imgui
    ${CMAKE_CURRENT_SOURCE_DIR}/include/imgui/backends
)

# Source files
file(GLOB_RECURSE IMGUI_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/imgui/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/imgui/backends/*.cpp
)

add_library(LeviViewModel SHARED
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
    ${IMGUI_SOURCES}
)

# Link libraries
target_link_libraries(LeviViewModel
    android
    log
    GLESv3
    EGL
)
