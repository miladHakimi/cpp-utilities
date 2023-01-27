add_library(Vector Vector.cpp)

target_include_directories(Vector INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(Vector PUBLIC tutorial_compiler_flags)