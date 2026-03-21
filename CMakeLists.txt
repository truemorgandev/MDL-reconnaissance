cmake_minimum_required(VERSION 3.16)

project(mdl-recon)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)
find_package(GLEW REQUIRED)

add_library(imgui
    external/imgui/imgui.cpp
    external/imgui/imgui_draw.cpp
    external/imgui/imgui_tables.cpp
    external/imgui/imgui_widgets.cpp
    external/imgui/backends/imgui_impl_glfw.cpp
    external/imgui/backends/imgui_impl_opengl3.cpp
)

target_include_directories(imgui PUBLIC
    external/imgui
    external/imgui/backends
)

add_executable(mdl-recon
    src/main.cpp
    src/loader/loader.cpp
)

target_include_directories(mdl-recon PRIVATE
    src
    src/core/module
    src/loader
    src/core/context
    external/imgui
    external/imgui/backends
)

target_link_libraries(mdl-recon PRIVATE
    imgui
    glfw
    OpenGL::GL
    GLEW::GLEW
    dl
)