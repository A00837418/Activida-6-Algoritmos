
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

TEST(PalindromoTest, PalindromoClasico) {
    string entrada = "abacdfgdcaba";
    auto resultado = encontrar_palindromo_real(entrada);
    
    EXPECT_EQ(resultado.second, "aba");   // "aba" es el palíndromo más largo
    EXPECT_EQ(resultado.first.first, 1);  // Posición 1-based
    EXPECT_EQ(resultado.first.second, 3); // "aba" ocupa posiciones 1 a 3
}

TEST(PalindromoTest, CadenaVacia) {
    string entrada = "";
    auto resultado = encontrar_palindromo_real(entrada);
    
    // Verifica que las posiciones sean (0, 0) y que el palíndromo esté vacío
    EXPECT_EQ(resultado.first.first, 0);  // Posición inicial
    EXPECT_EQ(resultado.first.second, 0); // Posición final
    EXPECT_EQ(resultado.second, "");      // Palíndromo encontrado
}