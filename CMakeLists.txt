
cmake_minimum_required(VERSION 3.16)

project(lab_4)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(basic
    src/main.cpp
    src/basic_algorithms.cpp
)

target_include_directories(basic PRIVATE include)

add_executable(task10
    src/task10_planets.cpp
)

add_executable(task11
    src/task11_tortoise_hare.cpp
)

foreach(target basic task10 task11)
    target_compile_options(${target} PRIVATE
        -Wall
        -Wextra
        -Wpedantic
    )
endforeach()
