
#include <gtest/gtest.h>
#include "text_analysis.h"

TEST(text_analysis_test, encuentra_substring_comun) {
    string s1 = "programacion";
    string s2 = "amacion";
    auto resultado = encontrar_substring_comun_real(s1, s2);
    EXPECT_EQ(resultado.second, "amacion");
    EXPECT_EQ(resultado.first.first, 6);  // índice de inicio en s1
    EXPECT_EQ(resultado.first.second, 12); // índice de fin (inclusive)
}

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

TEST(TextAnalysisTest, SinSubstringComun) {
    auto resultado = encontrar_substring_comun_real("abc", "xyz");
    EXPECT_EQ(resultado.second, "");
    EXPECT_EQ(resultado.first.first, 0);
    EXPECT_EQ(resultado.first.second, 0);
}

// Test para encontrar_substring_comun_real
TEST(TextAnalysisTest, SubstringComun) {
    auto resultado = encontrar_substring_comun_real("computadora", "toradora");
    EXPECT_EQ(resultado.second, "adora");
    EXPECT_EQ(resultado.first.second - resultado.first.first + 1, resultado.second.length());
}

TEST(TextAnalysisTest, SubcadenaComunInexistente) {
    std::string s1 = "abc";
    std::string s2 = "xyz";

    auto resultado = encontrar_substring_comun_real(s1, s2);

    EXPECT_EQ(resultado.first.first, 0);
    EXPECT_EQ(resultado.first.second, 0);
    EXPECT_EQ(resultado.second, "");
}

TEST(TextAnalysisTest, SubcadenaComunExistente) {
    std::string s1 = "abcdef";
    std::string s2 = "zabcy";

    auto resultado = encontrar_substring_comun_real(s1, s2);

    EXPECT_EQ(resultado.first.first, 1);   // 'abc' empieza en pos 1 de s1
    EXPECT_EQ(resultado.first.second, 3);
    EXPECT_EQ(resultado.second, "abc");
}

TEST(TextAnalysisTest, SubcadenaComunCadenasVacias) {
    std::string s1 = "";
    std::string s2 = "";

    auto resultado = encontrar_substring_comun_real(s1, s2);

    EXPECT_EQ(resultado.first.first, 0);
    EXPECT_EQ(resultado.first.second, 0);
    EXPECT_EQ(resultado.second, "");
}

