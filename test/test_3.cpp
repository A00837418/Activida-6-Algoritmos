
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

// 🔹 Test 1: Substring común simple → cubre dp[][], coincidencia, cálculo
TEST(SubstringComunTest, SubstringComunNormal) {
    auto resultado = encontrar_substring_comun_real("abcde", "cdefg");
    EXPECT_EQ(resultado.first.first, 3);   // posición inicial en s1
    EXPECT_EQ(resultado.first.second, 5);  // posición final en s1
    EXPECT_EQ(resultado.second, "cde");
}

// 🔹 Test 2: No hay substring común → cubre retorno vacío
TEST(SubstringComunTest, SinSubstringComun) {
    auto resultado = encontrar_substring_comun_real("abc", "xyz");
    EXPECT_EQ(resultado.first.first, 0);
    EXPECT_EQ(resultado.first.second, 0);
    EXPECT_EQ(resultado.second, "");
}

// 🔹 Test 3: Substring común está al principio
TEST(SubstringComunTest, SubstringInicio) {
    auto resultado = encontrar_substring_comun_real("abcxyz", "abc123");
    EXPECT_EQ(resultado.second, "abc");
    EXPECT_EQ(resultado.first.first, 1);  // posición en s1
    EXPECT_EQ(resultado.first.second, 3);
}

// 🔹 Test 4: Substring común al final
TEST(SubstringComunTest, SubstringFinal) {
    auto resultado = encontrar_substring_comun_real("123xyz", "abcxyz");
    EXPECT_EQ(resultado.second, "xyz");
    EXPECT_EQ(resultado.first.first, 4);
    EXPECT_EQ(resultado.first.second, 6);
}

// 🔹 Test 5: Substring común completo (s1 y s2 iguales)
TEST(SubstringComunTest, CadenasIguales) {
    auto resultado = encontrar_substring_comun_real("igual", "igual");
    EXPECT_EQ(resultado.second, "igual");
    EXPECT_EQ(resultado.first.first, 1);
    EXPECT_EQ(resultado.first.second, 5);
}