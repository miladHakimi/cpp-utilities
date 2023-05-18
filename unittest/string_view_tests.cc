#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../String/string_view.h"

#include <string>
#include <iostream>

namespace utilities {
namespace {

TEST(StringView, ConstructorCheck) {
    StringView view("Hello");
    EXPECT_EQ(view.size(), 5);
    const char *d = "salam";
    EXPECT_EQ(std::string(view.data()), std::string("Hello"));
    std::string str("Hello2");
    StringView view2(str);
    EXPECT_EQ(view2.size(), 6);
    EXPECT_EQ(std::string(view2.data()), std::string("Hello2"));

    StringView view3(view2);
    EXPECT_EQ(view3.size(), 6);
    EXPECT_EQ(std::string(view3.data()), std::string("Hello2"));
}

TEST(StringView, IndexCheck) {
    StringView view("Hello");
    EXPECT_EQ(view[0], 'H');
    EXPECT_EQ(view[1], 'e');
    EXPECT_EQ(view[2], 'l');
    EXPECT_EQ(view[3], 'l');
    EXPECT_EQ(view[4], 'o');
    ASSERT_DEATH(view[5], "Index out of range");
}

}  // namespace
}  // namespace utilities
