add_executable(
    container_test
    array_tests.cc
    vector_tests.cc
)

target_link_libraries(
    container_test
    tutorial_compiler_flags
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(container_test)
add_custom_target(check COMMAND container_test)
add_dependencies(check container_test)