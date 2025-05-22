
#include <gtest/gtest.h>
#include "text_analysis.h"  // Ajusta la ruta si está en otra carpeta

// Caso de prueba para buscar_patron_con_posicion
TEST(text_analysis_test, busca_patron) {
    string texto = "Hola mundo desde C++";
    string patron = "mundo";
    auto resultado = buscar_patron_con_posicion(texto, patron);
    EXPECT_TRUE(resultado.first);
    EXPECT_EQ(resultado.second, 6);  // "mundo" comienza en posición 6 (1-based)
}