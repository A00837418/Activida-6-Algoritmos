
#include <gtest/gtest.h>
#include "text_analysis.h"  // Ajusta la ruta si está en otra carpeta


// Test para buscar_patron_con_posicion
TEST(TextAnalysisTest, buscar_patron_existente) {
    auto resultado = buscar_patron_con_posicion("Hola mundo", "mundo");
    EXPECT_TRUE(resultado.first);
    EXPECT_EQ(resultado.second, 6);
}

TEST(TextAnalysisTest, buscar_patron_inexistente) {
    auto resultado = buscar_patron_con_posicion("Hola mundo", "adios");
    EXPECT_FALSE(resultado.first);
    EXPECT_EQ(resultado.second, 0);
}

// Test para encontrar_palindromo_real
TEST(TextAnalysisTest, PalindromoSimple) {
    auto resultado = encontrar_palindromo_real("abcba");
    EXPECT_EQ(resultado.first.first, 1);
    EXPECT_EQ(resultado.first.second, 5);
    EXPECT_EQ(resultado.second, "abcba");
}
