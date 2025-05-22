#include <gtest/gtest.h>
#include "text_analysis.h"

TEST(BusquedaPatronTest, PatronInexistente) {
    string texto = "Texto sin contenido malicioso aparente";
    string patron = "virus";

    auto [encontrado, posicion] = buscar_patron_con_posicion(texto, patron);

    EXPECT_FALSE(encontrado);
    EXPECT_EQ(posicion, 0);
}