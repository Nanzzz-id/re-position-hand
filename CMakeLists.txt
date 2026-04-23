cmake_minimum_required(VERSION 3.10.2)
project("LeviViewModel")

# Folder Header
include_directories(
    include
    include/imgui
    include/imgui/backends
)

# Ambil semua file .cpp ImGui
file(GLOB IMGUI_SOURCES 
    "src/imgui/*.cpp"
    "src/imgui/backends/imgui_impl_android.cpp"
    "src/imgui/backends/imgui_impl_opengl3.cpp"
)

add_library(LeviViewModel SHARED 
    src/main.cpp 
    ${IMGUI_SOURCES}
)

# Link library yang dibutuhkan untuk grafis
target_link_libraries(LeviViewModel
    android
    log
    GLESv3
    EGL
)
