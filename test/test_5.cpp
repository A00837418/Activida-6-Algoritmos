#include <gtest/gtest.h>
#include "text_analysis.h"

TEST(TextAnalysisTest, SinSubstringComun) {
    auto resultado = encontrar_substring_comun_real("abc", "xyz");
    EXPECT_EQ(resultado.second, "");
    EXPECT_EQ(resultado.first.first, 0);
    EXPECT_EQ(resultado.first.second, 0);
}