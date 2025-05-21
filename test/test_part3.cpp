#include <gtest/gtest.h>
#include "text_analysis.h"

TEST(SubstringComunTest, SubstringComunValido) {
    std::string t1 = "abcdefg";
    std::string t2 = "xyzabcde";
    auto [pos, sub] = encontrarSubstringComunReal(t1, t2);
    EXPECT_EQ(sub, "abcde");
    EXPECT_EQ(pos.first, 1);
    EXPECT_EQ(pos.second, 5);
}

TEST(SubstringComunTest, NoSubstringComun) {
    std::string t1 = "abc";
    std::string t2 = "xyz";
    auto [pos, sub] = encontrarSubstringComunReal(t1, t2);
    EXPECT_EQ(sub, "");
    EXPECT_EQ(pos.first, 0);
    EXPECT_EQ(pos.second, 0);
}
