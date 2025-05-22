
#include <gtest/gtest.h>
#include "text_analysis.h"

// Caso de prueba para encontrar_palindromo_real
TEST(text_analysis_test, encuentra_palindromo) {
    string texto = "Ferrocarrin mecanico";
    auto resultado = encontrar_palindromo_real(texto);
    EXPECT_EQ(resultado.second, "rr");
    EXPECT_EQ(resultado.first.first, 3);  // posición de la primera "r" en "Ferrocarrin"
    EXPECT_EQ(resultado.first.second, 4);  // posición de la segunda "r"
}
