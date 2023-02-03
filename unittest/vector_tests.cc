#include <gtest/gtest.h>

#include "../Vector/Vector.h"

namespace utilities {
namespace {

TEST(Vector, ConstructorCheck) {
  // Default constructor.
  Vector<int> v;
  EXPECT_EQ(v.Size(), 0);

  // Constructor with size.
  Vector<int> v2(10);
  EXPECT_EQ(v2.Size(), 10);

  // Copy Constructor.
  Vector<int> v3(v2);
  EXPECT_EQ(v3.Size(), 10);

  // Move Constructor.
  Vector<int> v4(std::move(v3));
  EXPECT_EQ(v4.Size(), 10);
  EXPECT_EQ(v3.Size(), 0);
  EXPECT_EQ(v3.Capacity(), 0);

  // Initializer list constructor.
  Vector<int> v5({1, 2, 3, 4, 5});
  EXPECT_EQ(v5.Size(), 5);
}

}  // namespace
}  // namespace utilities
