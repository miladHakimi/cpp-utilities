cmake_minimum_required(VERSION 3.10)

# #project name
project(cpp_test VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#specify the C++ standard.
add_library(tutorial_compiler_flags INTERFACE)
target_compile_features(tutorial_compiler_flags INTERFACE cxx_std_14)

add_subdirectory(Vector)
add_executable(Test unittests/main.cpp)

target_link_libraries(Test PUBLIC Vector)

target_include_directories(Test PUBLIC "${PROJECT_BINARY_DIR}")
