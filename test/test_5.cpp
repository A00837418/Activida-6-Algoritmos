
#include <gtest/gtest.h>
#include "text_analysis.h" 

TEST(text_analysis_test, substring_comun_al_inicio) {
    string s1 = "algebra";
    string s2 = "algoritmo";
    auto resultado = encontrar_substring_comun_real(s1, s2);
    EXPECT_EQ(resultado.second, "alg");
    EXPECT_EQ(resultado.first.first, 0);  // empieza en 'a' (índice 0)
    EXPECT_EQ(resultado.first.second, 2); // termina en 'g' (índice 2)
}