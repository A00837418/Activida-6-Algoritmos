
#include <gtest/gtest.h>
#include "text_analysis.h" 

TEST(text_analysis_test, substring_comun_en_medio) {
    string s1 = "ferrocarril";
    string s2 = "bicirrin";
    auto resultado = encontrar_substring_comun_real(s1, s2);
    EXPECT_EQ(resultado.second, "rri");
    EXPECT_EQ(resultado.first.first, 6);  // índice de 'r' en "rri"
    EXPECT_EQ(resultado.first.second, 8); // índice de 'i' en "rri"
}