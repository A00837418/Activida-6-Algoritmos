
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

TEST(TextAnalysisTest, PatronDetectado) {
    string texto = "abcdefg";
    string patron = "cde";
    auto [encontrado, pos] = buscar_patron_con_posicion(texto, patron);
    EXPECT_TRUE(encontrado);
    EXPECT_EQ(pos, 3);
}