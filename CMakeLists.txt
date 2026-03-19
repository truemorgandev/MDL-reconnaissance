cmake_minimum_required(VERSION 3.16)

project(mdl-recon)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(mdl-recon
    src/main.cpp
    src/loader/loader.cpp
)

target_include_directories(mdl-recon PRIVATE
    src
    src/core/module
    src/loader
    src/core/context
)

target_link_libraries(mdl-recon PRIVATE dl)