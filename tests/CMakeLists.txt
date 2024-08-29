include(CTest)
enable_testing()

add_executable(
  sample_tests
  hello_test.cpp
)
target_link_libraries(sample_tests
  GTest::gtest_main
  sample_lib
)

include(GoogleTest)
gtest_discover_tests(sample_tests)