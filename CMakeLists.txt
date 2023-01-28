cmake_minimum_required(VERSION 3.15)

# #project name
project(cpp_test VERSION 1.0)

#specify the C++ standard.
add_library(tutorial_compiler_flags INTERFACE)
target_compile_features(tutorial_compiler_flags INTERFACE cxx_std_17)

add_executable(Test unittests/main.cpp)

target_link_libraries(Test PUBLIC 
                        tutorial_compiler_flags
                        )
target_include_directories(Test PUBLIC "${PROJECT_BINARY_DIR}")
