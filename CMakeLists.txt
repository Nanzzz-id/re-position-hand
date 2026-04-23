cmake_minimum_required(VERSION 3.10.2)
project("LeviViewModel")

# Folder include
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/imgui)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/imgui/backends)

# Cari semua file .cpp di src dan imgui
file(GLOB_RECURSE SOURCES 
    "src/*.cpp"
    "src/imgui/*.cpp"
    "src/imgui/backends/*.cpp"
)

add_library(LeviViewModel SHARED ${SOURCES})

# Link library standar Android
target_link_libraries(LeviViewModel
    android
    log
    GLESv3
    EGL
)
