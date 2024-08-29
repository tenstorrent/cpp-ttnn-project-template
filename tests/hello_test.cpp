#include <gtest/gtest.h>

#include "sample/sample_class.hpp"

// Demonstrate some basic assertions.

TEST(HelloTest, AddTest) {
    // Expect two strings not to be equal.
    // Expect equality.
    EXPECT_EQ(sample::sum(7, 6), 13);
}