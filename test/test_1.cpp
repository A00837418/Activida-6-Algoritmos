
#include <gtest/gtest.h>
#include "text_analysis.h"  // Ajusta la ruta si está en otra carpeta

TEST(text_analysis_test, substring_comun_en_medio) {
    std::string s1 = "ferrocarril";
    std::string s2 = "bicirrin";

    auto resultado = encontrar_substring_comun_real(s1, s2);

    // Se espera que el substring común más largo sea "rri"
    EXPECT_EQ(resultado.second, "rri");

    // En "ferrocarril", "rri" empieza en el índice 7: "f e r r o c a **r r i** l"
    EXPECT_EQ(resultado.first.first, 7);  // Índice de inicio de "rri" en s1
    EXPECT_EQ(resultado.first.second, 9); // Índice de fin de "rri" en s1 (inclusive)
}