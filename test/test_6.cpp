
#include <gtest/gtest.h>
#include "text_analysis.h" 

TEST(text_analysis_test, substring_comun_en_medio) {
    string s1 = "ferrocarril";
    string s2 = "bicirrin";
    auto resultado = encontrar_substring_comun_real(s1, s2);
    EXPECT_EQ(resultado.second, "rri");
    EXPECT_EQ(resultado.first.first, 7);  // 'r' de "carril" en índice 7
    EXPECT_EQ(resultado.first.second, 9); // termina en 'i' (índice 9)
}