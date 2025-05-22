
#include <gtest/gtest.h>
#include "text_analysis.h"  // Ajusta la ruta si está en otra carpeta

TEST(BuscarPatronTest, PatronPresente) {
    std::string texto = "abcde123abcde";
    std::string patron = "123";
    auto resultado = buscar_patron_con_posicion(texto, patron);
    EXPECT_TRUE(resultado.first);
    EXPECT_EQ(resultado.second, 6);
}