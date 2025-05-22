
#include <gtest/gtest.h>
#include "text_analysis.h"  // Ajusta la ruta si está en otra carpeta

TEST(SubstringComunTest, SubstringComunNormal) {
    auto resultado = encontrar_substring_comun_real("abcde", "cdefg");
    EXPECT_EQ(resultado.first.first, 3);   // posición inicial en s1
    EXPECT_EQ(resultado.first.second, 5);  // posición final en s1
    EXPECT_EQ(resultado.second, "cde");
}