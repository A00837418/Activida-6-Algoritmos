#include "text_analysis.h"
#include <gtest/gtest.h>

// Caso de prueba para encontrar_palindromo_real
TEST(text_analysis_test, encuentra_palindromo) {
    string texto = "anita lava la tina";
    auto resultado = encontrar_palindromo_real(texto);
    EXPECT_EQ(resultado.second, "anita lava la tina");
    EXPECT_EQ(resultado.first.first, 1);  // inicio
    EXPECT_EQ(resultado.first.second, texto.length());  // fin
}