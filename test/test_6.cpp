
#include <gtest/gtest.h>
#include "text_analysis.h" 


TEST(text_analysis_test, substring_comun_al_final) {
    string s1 = "matematicas";
    string s2 = "fisica";
    auto resultado = encontrar_substring_comun_real(s1, s2);
    EXPECT_EQ(resultado.second, "ica");
    EXPECT_EQ(resultado.first.first, 7);  // índice de 'i' en "ica"
    EXPECT_EQ(resultado.first.second, 9); // índice de 'a' en "ica"
}