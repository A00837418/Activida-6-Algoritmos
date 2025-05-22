
#include "text_analysis.h"
#include <gtest/gtest.h>

TEST(TextAnalysisTest, encuentra_palindromo) {
    string texto = "anita lava la tina";
    auto [pos, pal] = encontrar_palindromo_real(texto);
    EXPECT_EQ(pal, "ava");
}

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

TEST(TextAnalysisTest, PalindromoCadenaVacia) {
    std::string vacio = "";
    auto resultado = encontrar_palindromo_real(vacio);

    EXPECT_EQ(resultado.first.first, 0);
    EXPECT_EQ(resultado.first.second, 0);
    EXPECT_EQ(resultado.second, "");
}

// Caso de prueba para encontrar_palindromo_real
TEST(TextAnalysisTest, encuentra_palindromo) {
    string texto = "Ferrocarrin mecanico";
    auto resultado = encontrar_palindromo_real(texto);
    EXPECT_EQ(resultado.second, "rr");
    EXPECT_EQ(resultado.first.first, 3);  // posición de la primera "r" en "Ferrocarrin"
    EXPECT_EQ(resultado.first.second, 4);  // posición de la segunda "r"
}