#include <gtest/gtest.h>
#include "text_analysis.h"

TEST(text_analysis_test, encuentra_substring_comun) {
    string s1 = "programacion";
    string s2 = "amacion";
    auto resultado = encontrar_substring_comun_real(s1, s2);
    EXPECT_EQ(resultado.second, "amacion");
    EXPECT_EQ(resultado.first.first, 6);  // índice de inicio en s1
    EXPECT_EQ(resultado.first.second, 12); // índice de fin (inclusive)
}
