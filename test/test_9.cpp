#include <gtest/gtest.h>
#include "text_analysis.h"

// Test para buscar_patron_con_posicion
TEST(text_analysis_test, buscar_patron_existente) {
    auto resultado = buscar_patron_con_posicion("Hola mundo", "mundo");
    EXPECT_TRUE(resultado.first);
    EXPECT_EQ(resultado.second, 6);
}

TEST(text_analysis_test, buscar_patron_inexistente) {
    auto resultado = buscar_patron_con_posicion("Hola mundo", "adios");
    EXPECT_FALSE(resultado.first);
    EXPECT_EQ(resultado.second, 0);
}
