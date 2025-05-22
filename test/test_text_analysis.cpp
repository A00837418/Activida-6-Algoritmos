
#include <gtest/gtest.h>
#include "text_analysis.h"


TEST(TextAnalysisTest, buscar_patron_con_posicion) {
    // Texto completo (t1)
    std::string t1 = "Este es un texto de prueba donde buscamos un patrón específico.";
    // Patrón a buscar (m1)
    std::string m1 = "patrón";

    auto [found, pos] = buscar_patron_con_posicion(t1, m1);

    // El patrón "patrón" sí está en t1, y su posición debe ser > 0
    EXPECT_TRUE(found);
    EXPECT_GT(pos, 0u);
}

