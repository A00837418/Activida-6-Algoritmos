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


#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

string leerArchivo(const string& ruta) {
    ifstream archivo(ruta);
    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo: " << ruta << endl;
        return "";
    }
    string contenido((istreambuf_iterator<char>(archivo)), istreambuf_iterator<char>());
    contenido.erase(remove(contenido.begin(), contenido.end(), '\r'), contenido.end());
    return contenido;
}

pair<bool, size_t> buscarPatronConPosicion(const string& texto, const string& patron) {
    size_t pos = texto.find(patron);
    if (pos == string::npos) return {false, 0};
    return {true, pos + 1}; // 1-based
}

pair<pair<size_t, size_t>, string> encontrarPalindromoReal(const string& s) {
    size_t n = s.length();
    if (n == 0) return {{0, 0}, ""};

    size_t max_len = 1;
    size_t start = 0;

    for (size_t i = 0; i < n; i++) {
        // Palíndromos impares
        size_t l = i, r = i;
        while (l <= r && r < n && s[l] == s[r]) {
            if (r - l + 1 > max_len) {
                max_len = r - l + 1;
                start = l;
            }
            if (l == 0) break;
            l--;
            r++;
        }

        // Palíndromos pares
        l = i;
        r = i + 1;
        while (l <= r && r < n && s[l] == s[r]) {
            if (r - l + 1 > max_len) {
                max_len = r - l + 1;
                start = l;
            }
            if (l == 0) break;
            l--;
            r++;
        }
    }

    string palindromo = s.substr(start, max_len);
    size_t pos_final = start + max_len;
    return {{start + 1, pos_final}, palindromo};
}

pair<pair<size_t, size_t>, string> encontrarSubstringComunReal(const string& s1, const string& s2) {
    size_t m = s1.length();
    size_t n = s2.length();
    vector<vector<size_t>> dp(m + 1, vector<size_t>(n + 1, 0));
    size_t max_len = 0;
    size_t end = 0;

    for (size_t i = 1; i <= m; i++) {
        for (size_t j = 1; j <= n; j++) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
                if (dp[i][j] > max_len) {
                    max_len = dp[i][j];
                    end = i;
                }
            }
        }
    }

    if (max_len == 0) return {{0, 0}, ""};

    string substring = s1.substr(end - max_len, max_len);
    return {{end - max_len + 1, end}, substring};
}

int main() {
    string t1 = leerArchivo("Textos/transmission1.txt");
    string t2 = leerArchivo("Textos/transmission2.txt");
    string m1 = leerArchivo("Textos/mcode1.txt");
    string m2 = leerArchivo("Textos/mcode2.txt");
    string m3 = leerArchivo("Textos/mcode3.txt");

    cout << "Parte 1:" << endl;
    
    auto [found1, pos1] = buscarPatronConPosicion(t1, m1);
    cout << (found1 ? "true " + to_string(pos1) : "false") << endl;

    auto [found2, pos2] = buscarPatronConPosicion(t1, m2);
    cout << (found2 ? "true " + to_string(pos2) : "false") << endl;

    auto [found3, pos3] = buscarPatronConPosicion(t1, m3);
    cout << (found3 ? "true " + to_string(pos3) : "false") << endl;

    auto [found4, pos4] = buscarPatronConPosicion(t2, m1);
    cout << (found4 ? "true " + to_string(pos4) : "false") << endl;

    auto [found5, pos5] = buscarPatronConPosicion(t2, m2);
    cout << (found5 ? "true " + to_string(pos5) : "false") << endl;

    auto [found6, pos6] = buscarPatronConPosicion(t2, m3);
    cout << (found6 ? "true " + to_string(pos6) : "false") << endl;

    cout << "Parte 2:" << endl;
    auto [pal1_pos, pal1_str] = encontrarPalindromoReal(t1);
    replace(pal1_str.begin(), pal1_str.end(), '\n', ' ');
    cout << pal1_pos.first << " " << pal1_pos.second << " " << pal1_str << endl;

    auto [pal2_pos, pal2_str] = encontrarPalindromoReal(t2);
    replace(pal2_str.begin(), pal2_str.end(), '\n', ' ');
    cout << pal2_pos.first << " " << pal2_pos.second << "" << pal2_str << endl;

    cout << "Parte 3:" << endl;
    auto [sub_pos, sub_str] = encontrarSubstringComunReal(t1, t2);
    cout << sub_pos.first << " " << sub_pos.second << " " << sub_str << endl;

    return 0;
}
