#include <gtest/gtest.h>
#include "text_analysis.h"

// Tests sin archivos externos, usando textos hardcodeados

TEST(TextAnalysisTest, BuscarPatronConPosicion) {
    // Texto completo (t1)
    std::string t1 = "Este es un texto de prueba donde buscamos un patrón específico.";
    // Patrón a buscar (m1)
    std::string m1 = "patrón";

    auto [found, pos] = buscarPatronConPosicion(t1, m1);

    // El patrón "patrón" sí está en t1, y su posición debe ser > 0
    EXPECT_TRUE(found);
    EXPECT_GT(pos, 0u);
}

TEST(TextAnalysisTest, EncontrarPalindromoReal) {
    // Texto que contiene un palíndromo, por ejemplo "ana"
    std::string t2 = "En este texto encontramos un palíndromo: ana.";

    auto [pos_range, pal] = encontrarPalindromoReal(t2);

    // Validar que se encontró un palíndromo no vacío
    EXPECT_FALSE(pal.empty());
    EXPECT_GE(pos_range.first, 0u);
    EXPECT_GE(pos_range.second, pos_range.first);

    // Opcional: Comprobar que el palíndromo encontrado sea efectivamente "ana"
    EXPECT_EQ(pal, "ana");
}
