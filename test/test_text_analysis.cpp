
/*
 *  E1. Actividad Integradora 1
 * 
 *  Descripción: Programa que lee archivos de texto y código malicioso, detecta patrones,
 *              encuentra palíndromos y substrings comunes.
 *  Programadores : 
 *   
 *   Francisco Eduardo Pérez Berlanga - A00837418
 *
 *   Paulo de Jesus Ibarra Carballo a00837745 
 *
 *   Claudio Patricio Cantú Alanís a00835868
 *  
 *    Pedro Alejandro Rodriguez Gonzalez a00837473
 *
 *   Diego José Roca Rodríguez a00836390
 *
 *  Fecha: 5 de abril de 2025
 */

#include "text_analysis.h"
#include <gtest/gtest.h>


TEST(TextAnalysisTest, EncuentraPalindromo) {
    string texto = "anita lava la tina";
    auto [pos, pal] = encontrar_palindromo_real(texto);
    EXPECT_EQ(pal, "anita lava la tina");
}