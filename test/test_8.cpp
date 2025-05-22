#include <gtest/gtest.h>
#include "text_analysis.h"

// Test para encontrar_substring_comun_real
TEST(TextAnalysisTest, SubstringComun) {
    auto resultado = encontrar_substring_comun_real("computadora", "toradora");
    EXPECT_EQ(resultado.second, "adora");
    EXPECT_EQ(resultado.first.second - resultado.first.first + 1, resultado.second.length());
}

TEST(TextAnalysisTest, SinSubstringComun) {
    auto resultado = encontrar_substring_comun_real("abc", "xyz");
    EXPECT_EQ(resultado.second, "");
    EXPECT_EQ(resultado.first.first, 0);
    EXPECT_EQ(resultado.first.second, 0);
}