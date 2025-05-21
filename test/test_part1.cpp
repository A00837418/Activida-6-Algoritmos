#include <gtest/gtest.h>
#include "text_analysis.h"

TEST(BuscarPatronTest, PatronEncontrado) {
    std::string texto = "Este es un texto de prueba con un patrón.";
    std::string patron = "texto";
    auto resultado = buscarPatronConPosicion(texto, patron);
    EXPECT_TRUE(resultado.first);
    EXPECT_EQ(resultado.second, 12); // "texto" empieza en la posición 12 (1-based)
}

TEST(BuscarPatronTest, PatronNoEncontrado) {
    std::string texto = "Contenido de prueba sin coincidencias.";
    std::string patron = "inexistente";
    auto resultado = buscarPatronConPosicion(texto, patron);
    EXPECT_FALSE(resultado.first);
    EXPECT_EQ(resultado.second, 0);
}
