#include <gtest/gtest.h>
#include "text_analysis.h"

using namespace std;

TEST(SubstringComunTest, SubstringComunValido) {
    string s1 = "abcde";
    string s2 = "zabcx";
    auto resultado = encontrarSubstringComunReal(s1, s2);
    auto pos = resultado.first;
    auto substring = resultado.second;
    EXPECT_EQ(pos.first, 0);  // empieza en 0 en s1
    EXPECT_EQ(pos.second, 2); // termina en 2 en s1
    EXPECT_EQ(substring, "abc");
}

TEST(SubstringComunTest, NoSubstringComun) {
    string s1 = "abc";
    string s2 = "xyz";
    auto resultado = encontrarSubstringComunReal(s1, s2);
    auto pos = resultado.first;
    auto substring = resultado.second;
    EXPECT_EQ(substring, "");
    EXPECT_EQ(pos.first, string::npos);
    EXPECT_EQ(pos.second, string::npos);
}
