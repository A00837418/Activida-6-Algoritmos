#include "text_analysis.h"
#include <gtest/gtest.h>

// Caso de prueba para encontrar_substring_comun_real
TEST(text_analysis_test, encuentra_substring_comun) {
    string s1 = "programacion";
    string s2 = "amacion";
    auto resultado = encontrar_substring_comun_real(s1, s2);
    EXPECT_EQ(resultado.second, "amacion");
    EXPECT_EQ(resultado.first.first, 5);  // "a" empieza en posición 5 en s1
    EXPECT_EQ(resultado.first.second, 11);
}
