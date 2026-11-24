cmake_minimum_required(VERSION 3.16)
project(oc-rotation-tool CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ocrotationtool
    src/main.cpp
    src/pool.cpp
    src/rotate.cpp
    src/inject.cpp
)

target_include_directories(ocrotationtool PRIVATE include)

if(WIN32)
    target_link_libraries(ocrotationtool PRIVATE userenv)
endif()
