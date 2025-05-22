#include <gtest/gtest.h>
#include "text_analysis.h"

using namespace std;

TEST(BuscarPatronTest, PatronEncontrado) {
    string texto = "Hola mundo cruel";
    string patron = "mundo";
    auto resultado = buscarpatronconposicion(texto, patron);
    EXPECT_TRUE(resultado.first);
    EXPECT_EQ(resultado.second, 5); // posición donde empieza "mundo"
}

TEST(BuscarPatronTest, PatronNoEncontrado) {
    string texto = "Hola mundo cruel";
    string patron = "gato";
    auto resultado = buscarpatronconposicion(texto, patron);
    EXPECT_FALSE(resultado.first);
    EXPECT_EQ(resultado.second, string::npos);
}