#include <gtest/gtest.h>

#include "../Array/array.h"

namespace utilities {
namespace {

TEST(Array, ConstructorCheck) {
  // Default constructor.
  Array<int, 2> v;
  EXPECT_EQ(v.Size(), 2);
  memset(v.Data(), 0, sizeof(int) * v.Size());
  for (int i = 0; i < v.Size(); ++i) {
    EXPECT_EQ(v[i], 0);
  }

  // Copy Constructor.
  Array<int, 2> v3(v);
  EXPECT_EQ(v3.Size(), 2);

  // Move Constructor.
  Array<int, 2> v4(std::move(v3));
  EXPECT_EQ(v4.Size(), 2);
  EXPECT_EQ(v3.Data(), nullptr);
}

TEST(Array, AssignmentCheck) {
  // Copy assignment.
  Array<int, 2> v;
  v[0] = 1;
  v[1] = 2;
  Array<int, 2> v2;
  v2 = v;
  EXPECT_EQ(v2[0], 1);
  EXPECT_EQ(v2[1], 2);

  // Move assignment.
  Array<int, 2> v3;
  v3 = std::move(v2);
  EXPECT_EQ(v3[0], 1);
  EXPECT_EQ(v3[1], 2);

  EXPECT_EQ(v2.Data(), nullptr);
}

}  // namespace
}  // namespace utilities
