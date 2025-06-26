cmake_minimum_required(VERSION 3.17)
project(eo_q_peek)

set(CMAKE_CXX_STANDARD 20)

add_executable(eo_q_peek
    eo_q_peek/src/main.cpp
    eo_q_peek/src/window.cpp
    eo_q_peek/src/thumbnail.cpp
    eo_q_peek/src/utils.cpp
)

target_link_libraries(eo_q_peek
    dwmapi
    user32
    gdi32
)
