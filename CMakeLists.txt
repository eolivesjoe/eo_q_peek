cmake_minimum_required(VERSION 3.17)
project(eo_q_peek)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/lib)


add_executable(eo_q_peek
    eo_q_peek/src/main.cpp
    eo_q_peek/src/app/app.cpp
    eo_q_peek/src/window/window.cpp
    eo_q_peek/src/thumbnail/thumbnail.cpp
    eo_q_peek/src/utils/utils.cpp
    eo_q_peek/src/logger/logger.cpp
)

target_link_libraries(eo_q_peek
    dwmapi
    user32
    gdi32
)
