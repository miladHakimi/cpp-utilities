add_executable(
    vector_test
    vector_tests.cc
)

target_link_libraries(
    vector_test
    tutorial_compiler_flags
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(vector_test)
add_custom_target(check COMMAND vector_test)
add_dependencies(check vector_test)