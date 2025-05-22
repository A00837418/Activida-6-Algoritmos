
#include <gtest/gtest.h>
#include "text_analysis.h"  // Ajusta la ruta si está en otra carpeta

// Caso de prueba para buscar_patron_con_posicion
TEST(text_analysis_test, busca_patron) {
    string texto = "Hola mundo desde C++";
    string patron = "mundo";
    auto resultado = buscar_patron_con_posicion(texto, patron);
    EXPECT_TRUE(resultado.first);
    EXPECT_EQ(resultado.second, 6);  // "mundo" comienza en posición 6 (1-based)
}

// Test para buscar_patron_con_posicion
TEST(text_analysis_test, buscar_patron_existente) {
    auto resultado = buscar_patron_con_posicion("Hola mundo", "mundo");
    EXPECT_TRUE(resultado.first);
    EXPECT_EQ(resultado.second, 6);
}

TEST(text_analysis_test, buscar_patron_inexistente) {
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
