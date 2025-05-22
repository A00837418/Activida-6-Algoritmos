
#include "text_analysis.h"
#include <gtest/gtest.h>

TEST(text_analysis_test, encuentra_palindromo) {
    string texto = "anita lava la tina";
    auto [pos, pal] = encontrar_palindromo_real(texto);
    EXPECT_EQ(pal, "anita lava la tina");
}