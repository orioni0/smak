cmake_minimum_required(VERSION 3.20)
project(RayTracer VERSION 1.0.0 LANGUAGES CXX)

add_executable(test 
    src/main.cpp
    src/utils.cpp
    src/vec3.cpp
    src/transformations.cpp
    src/ray.cpp
    src/camera.cpp
    src/hit.cpp
)
target_include_directories(test PUBLIC include)
