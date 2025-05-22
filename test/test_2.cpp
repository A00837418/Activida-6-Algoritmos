
#include "text_analysis.h"
#include <gtest/gtest.h>

// Test para encontrar_palindromo_real
TEST(TextAnalysisTest, PalindromoSimple) {
    auto resultado = encontrar_palindromo_real("abcba");
    EXPECT_EQ(resultado.first.first, 1);
    EXPECT_EQ(resultado.first.second, 5);
    EXPECT_EQ(resultado.second, "abcba");
}

TEST(TextAnalysisTest, PalindromoPar) {
    auto resultado = encontrar_palindromo_real("abccba");
    EXPECT_EQ(resultado.second, "abccba");
}

TEST(TextAnalysisTest, PalindromoEnMedio) {
    auto resultado = encontrar_palindromo_real("xyzracecar123");
    EXPECT_EQ(resultado.second, "racecar");
}