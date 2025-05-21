#include <gtest/gtest.h>
#include "text_analysis.h"

using namespace std;

TEST(PalindromoTest, DetectaPalindromoCentral) {
    string texto = "abc racecar def";
    auto resultado = encontrarPalindromoReal(texto);
    auto pos = resultado.first;
    auto palindromo = resultado.second;
    EXPECT_EQ(pos.first, 4);  // "racecar" empieza en 4
    EXPECT_EQ(pos.second, 10); // termina en 10
    EXPECT_EQ(palindromo, "racecar");
}

TEST(PalindromoTest, PalindromoSimple) {
    string texto = " wow ";
    auto resultado = encontrarPalindromoReal(texto);
    auto pos = resultado.first;
    auto palindromo = resultado.second;
    EXPECT_EQ(pos.first, 1);  // 'w'
    EXPECT_EQ(pos.second, 3); // 'w'
    EXPECT_EQ(palindromo, "wow");
}
