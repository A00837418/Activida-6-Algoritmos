
/*
 * SonarQube, herramienta de gestión de calidad de software de código abierto.
 * Copyright (C) 2008-2013 SonarSource
 * http://github.com/SonarOpenCommunity/sonar-cxx
 *
 * SonarQube es un software libre; puedes redistribuirlo y/o
 * modificarlo según los términos de la Licencia Pública General Reducida de GNU
 * Licencia publicada por la Free Software Foundation; ya sea
 * versión 3 de la Licencia, o (a su elección) cualquier versión posterior.
 *
 * SonarQube se distribuye con la esperanza de que sea útil,
 * pero SIN NINGUNA GARANTÍA; sin siquiera la garantía implícita de
 * COMERCIABILIDAD o IDONEIDAD PARA UN PROPÓSITO PARTICULAR. Véase la GNU
 * Licencia Pública General Reducida para más detalles.
 *
 * Debería haber recibido una copia de la Licencia Pública General Reducida de GNU
 * junto con este programa; si no, escriba a la Free Software Foundation,
 * Inc., 51 Franklin Street, quinto piso, Boston, MA 02110-1301, EE. UU.
 */
 
#include "text_analysis.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void analizar_patrones(const string& texto, const vector<string>& codigos) {
    for (const auto& codigo : codigos) {
        auto [found, pos] = buscar_patron_con_posicion(texto, codigo);
        cout << (found ? "true " + to_string(pos) : "false") << endl;
    }
}

void encontrar_palindromos(const string& texto) {
    auto [pos, pal] = encontrar_palindromo_real(texto);
    replace(pal.begin(), pal.end(), '\n', ' ');
    cout << pos.first << " " << pos.second << " " << pal << endl;
}

void encontrar_subcadena(const string& t1, const string& t2) {
    auto [pos, sub] = encontrar_subcadena_comun_real(t1, t2);
    cout << pos.first << " " << pos.second << " " << sub << endl;
}

int main() {
    string t1 = leer_archivo("Textos/transmission1.txt");
    string t2 = leer_archivo("Textos/transmission2.txt");
    string m1 = leer_archivo("Textos/mcode1.txt");
    string m2 = leer_archivo("Textos/mcode2.txt");
    string m3 = leer_archivo("Textos/mcode3.txt");

    cout << "Parte 1:" << endl;
    analizar_patrones(t1, {m1, m2, m3});
    analizar_patrones(t2, {m1, m2, m3});

    cout << "Parte 2:" << endl;
    encontrar_palindromos(t1);
    encontrar_palindromos(t2);

    cout << "Parte 3:" << endl;
    encontrar_subcadena(t1, t2);

    return 0;
}
