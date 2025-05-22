
#include <gtest/gtest.h>
#include "text_analysis.h"

TEST(text_analysis_test, substring_comun_al_inicio) {
    string s1 = "algebra";
    string s2 = "algoritmo";
    auto resultado = encontrar_substring_comun_real(s1, s2);

    // El substring común esperado es "alg"
    EXPECT_EQ(resultado.second, "alg");

    // Validamos que las posiciones indican la subcadena correcta en s1
    int inicio = resultado.first.first;
    int fin = resultado.first.second;
    string encontrado = s1.substr(inicio, fin - inicio + 1);
    EXPECT_EQ(encontrado, "alg");
}
