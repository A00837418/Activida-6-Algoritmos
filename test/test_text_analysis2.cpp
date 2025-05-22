#include <gtest/gtest.h>
#include "text_analysis.h"

TEST(TextAnalysisTest, buscar_patron_con_posicion) {
    std::string texto = "Este es un ejemplo simple de búsqueda.";
    std::string patron = "ejemplo";
    auto resultado = buscar_patron_con_posicion(texto, patron);
    EXPECT_TRUE(resultado.first);
    EXPECT_EQ(resultado.second, texto.find(patron) + 1);
}
