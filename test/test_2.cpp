
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

// 🔹 2. Cubre: Palíndromo impar ("racecar") → se ejecutan llamadas expandir_desde_centro(s, i, i, ...)
TEST(PalindromoTest, PalindromoImpar) {
    string entrada = "racecar";
    auto resultado = encontrar_palindromo_real(entrada);
    EXPECT_EQ(resultado.second, "racecar");
    EXPECT_EQ(resultado.first.first, 1);
    EXPECT_EQ(resultado.first.second, 7);
}

// 🔹 3. Cubre: Palíndromo par ("abccba") → se ejecutan expandir_desde_centro(s, i, i+1, ...)
TEST(PalindromoTest, PalindromoPar) {
    string entrada = "abccba";
    auto resultado = encontrar_palindromo_real(entrada);
    EXPECT_EQ(resultado.second, "abccba");
    EXPECT_EQ(resultado.first.first, 1);
    EXPECT_EQ(resultado.first.second, 6);
}

// 🔹 4. Cubre: palíndromo en el medio, verifica substr() y pos_final
TEST(PalindromoTest, PalindromoEnMedio) {
    string entrada = "abcxyzyxdef";
    auto resultado = encontrar_palindromo_real(entrada);
    EXPECT_EQ(resultado.second, "xyzyx");
    EXPECT_EQ(resultado.first.first, 4);  // 1-based index
    EXPECT_EQ(resultado.first.second, 8);
}

// 🔹 5. Palíndromo de un solo carácter
TEST(PalindromoTest, UnCaracter) {
    string entrada = "a";
    auto resultado = encontrar_palindromo_real(entrada);
    EXPECT_EQ(resultado.second, "a");
    EXPECT_EQ(resultado.first.first, 1);
    EXPECT_EQ(resultado.first.second, 1);
}