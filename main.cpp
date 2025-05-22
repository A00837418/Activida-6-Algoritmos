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
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    string t1 = leer_archivo("Textos/transmission1.txt");
    string t2 = leer_archivo("Textos/transmission2.txt");
    string m1 = leer_archivo("Textos/mcode1.txt");
    string m2 = leer_archivo("Textos/mcode2.txt");
    string m3 = leer_archivo("Textos/mcode3.txt");

    cout << "Parte 1:" << endl;
    
    auto [found1, pos1] = buscar_patron_con_posicion(t1, m1);
    cout << (found1 ? "true " + to_string(pos1) : "false") << endl;

    auto [found2, pos2] = buscar_patron_con_posicion(t1, m2);
    cout << (found2 ? "true " + to_string(pos2) : "false") << endl;

    auto [found3, pos3] = buscar_patron_con_posicion(t1, m3);
    cout << (found3 ? "true " + to_string(pos3) : "false") << endl;

    auto [found4, pos4] = buscar_patron_con_posicion(t2, m1);
    cout << (found4 ? "true " + to_string(pos4) : "false") << endl;

    auto [found5, pos5] = buscar_patron_con_posicion(t2, m2);
    cout << (found5 ? "true " + to_string(pos5) : "false") << endl;

    auto [found6, pos6] = buscar_patron_con_posicion(t2, m3);
    cout << (found6 ? "true " + to_string(pos6) : "false") << endl;

    cout << "Parte 2:" << endl;
    auto [pal1_pos, pal1_str] = encontrar_palindromo_real(t1);
    replace(pal1_str.begin(), pal1_str.end(), '\n', ' ');
    cout << pal1_pos.first << " " << pal1_pos.second << " " << pal1_str << endl;

    auto [pal2_pos, pal2_str] = encontrar_palindromo_real(t2);
    replace(pal2_str.begin(), pal2_str.end(), '\n', ' ');
    cout << pal2_pos.first << " " << pal2_pos.second << " " << pal2_str << endl;

    cout << "Parte 3:" << endl;
    auto [sub_pos, sub_str] = encontrar_substring_comun_real(t1, t2);
    cout << sub_pos.first << " " << sub_pos.second << " " << sub_str << endl;

    return 0;
}
