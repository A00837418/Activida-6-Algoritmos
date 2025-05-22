
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

using namespace std;

// Pruebas individuales de búsqueda de patrón
void pruebas_busqueda_patron(const string& t1, const string& t2, const string& m1, const string& m2, const string& m3) {
    cout << "Parte 1:" << endl;

    vector<pair<bool, size_t>> resultados = {
        buscar_patron_con_posicion(t1, m1),
        buscar_patron_con_posicion(t1, m2),
        buscar_patron_con_posicion(t1, m3),
        buscar_patron_con_posicion(t2, m1),
        buscar_patron_con_posicion(t2, m2),
        buscar_patron_con_posicion(t2, m3)
    };

    for (const auto& res : resultados) {
        cout << (res.first ? "true " + to_string(res.second) : "false") << endl;
    }
}

// Pruebas individuales de búsqueda de palíndromos
void pruebas_palindromos(const string& t1, const string& t2) {
    cout << "Parte 2:" << endl;

    auto [pal1_pos, pal1_str] = encontrar_palindromo_real(t1);
    replace(pal1_str.begin(), pal1_str.end(), '\n', ' ');
    cout << pal1_pos.first << " " << pal1_pos.second << " " << pal1_str << endl;

    auto [pal2_pos, pal2_str] = encontrar_palindromo_real(t2);
    replace(pal2_str.begin(), pal2_str.end(), '\n', ' ');
    cout << pal2_pos.first << " " << pal2_pos.second << " " << pal2_str << endl;
}

// Prueba individual de substring común
void prueba_substring_comun(const string& t1, const string& t2) {
    cout << "Parte 3:" << endl;

    auto [sub_pos, sub_str] = encontrar_substring_comun_real(t1, t2);
    cout << sub_pos.first << " " << sub_pos.second << " " << sub_str << endl;
}

int main() {
    string t1 = leer_archivo("Textos/transmission1.txt");
    string t2 = leer_archivo("Textos/transmission2.txt");
    string m1 = leer_archivo("Textos/mcode1.txt");
    string m2 = leer_archivo("Textos/mcode2.txt");
    string m3 = leer_archivo("Textos/mcode3.txt");

    if (t1.empty() || t2.empty() || m1.empty() || m2.empty() || m3.empty()) {
        cerr << "Error al leer uno o más archivos." << endl;
        return 1;
    }

    pruebas_busqueda_patron(t1, t2, m1, m2, m3);
    pruebas_palindromos(t1, t2);
    prueba_substring_comun(t1, t2);

    return 0;
}
