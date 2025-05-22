#include <gtest/gtest.h>
#include "text_analysis.h"

TEST(BusquedaPatronTest, PatronExistente) {
    string texto = "Este es un mensaje secreto con malware123";
    string patron = "malware123";

    auto [encontrado, posicion] = buscar_patron_con_posicion(texto, patron);

    EXPECT_TRUE(encontrado);
    EXPECT_EQ(posicion, 36);  // posición 1-based
}
