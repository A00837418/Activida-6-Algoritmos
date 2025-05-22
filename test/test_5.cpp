
#include <gtest/gtest.h>
#include "text_analysis.h" 

TEST(text_analysis_test, substring_comun_al_inicio) {
    string s1 = "algebra";
    string s2 = "algoritmo";
    auto resultado = encontrar_substring_comun_real(s1, s2);

    // Validamos el substring común
    EXPECT_EQ(resultado.second, "alg");

    // Validamos la posición del substring en s1
    string encontrado = s1.substr(resultado.first.first, resultado.first.second - resultado.first.first + 1);
    EXPECT_EQ(encontrado, "alg");
}