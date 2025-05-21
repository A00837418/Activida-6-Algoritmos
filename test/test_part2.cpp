#include <gtest/gtest.h>
#include "text_analysis.h"

TEST(PalindromoTest, DetectaPalindromoCentral) {
    std::string texto = "abc racecar def";
    auto [pos, pal] = encontrarPalindromoReal(texto);
    EXPECT_EQ(pal, "racecar");
    EXPECT_EQ(pos.first, 5); // posición 1-based
    EXPECT_EQ(pos.second, 11); 
}

TEST(PalindromoTest, PalindromoSimple) {
    std::string texto = "noon";
    auto [pos, pal] = encontrarPalindromoReal(texto);
    EXPECT_EQ(pal, "noon");
    EXPECT_EQ(pos.first, 1);
    EXPECT_EQ(pos.second, 4);
}
