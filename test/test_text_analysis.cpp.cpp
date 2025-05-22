#include <gtest/gtest.h>
#include "text_analysis.h"

// Nota: Ajusta las rutas a los archivos TXT según donde los tengas

TEST(TextAnalysisTest, BuscarPatronConPosicion) {
    string t1 = leerArchivo("Textos/transmission1.txt");
    string m1 = leerArchivo("Textos/mcode1.txt");

    auto [found, pos] = buscarPatronConPosicion(t1, m1);
    
    // Asumimos que el patrón m1 está en t1 y debe encontrarse en una posición > 0
    EXPECT_TRUE(found);
    EXPECT_GT(pos, 0u);
}

TEST(TextAnalysisTest, EncontrarPalindromoReal) {
    string t2 = leerArchivo("Textos/transmission2.txt");

    auto [pos_range, pal] = encontrarPalindromoReal(t2);

    // Validar que se encontró un palíndromo no vacío
    EXPECT_FALSE(pal.empty());
    EXPECT_GE(pos_range.first, 1u);
    EXPECT_GE(pos_range.second, pos_range.first);
}
