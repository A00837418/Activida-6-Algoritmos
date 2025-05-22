#include <gtest/gtest.h>
#include "text_analysis.h"

// Test para buscar_patron_con_posicion
TEST(TextAnalysisTest, BuscarPatronExistente) {
    auto resultado = buscar_patron_con_posicion("Hola mundo", "mundo");
    EXPECT_TRUE(resultado.first);
    EXPECT_EQ(resultado.second, 6);
}

TEST(TextAnalysisTest, BuscarPatronInexistente) {
    auto resultado = buscar_patron_con_posicion("Hola mundo", "adios");
    EXPECT_FALSE(resultado.first);
    EXPECT_EQ(resultado.second, 0);
}
