#ifndef TEXT_ANALYSIS_H
#define TEXT_ANALYSIS_H

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

/**
 * @brief Lee el contenido de un archivo de texto.
 * @param ruta Ruta del archivo a leer.
 * @return Contenido completo del archivo como una cadena.
 */
string leer_archivo(const string& ruta) {
    ifstream archivo(ruta);
    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo: " << ruta << endl;
        return "";
    }
    string contenido((istreambuf_iterator<char>(archivo)), istreambuf_iterator<char>());
    contenido.erase(remove(contenido.begin(), contenido.end(), '\r'), contenido.end());
    return contenido;
}

/**
 * @brief Busca un patrón dentro de un texto.
 * @param texto Texto donde buscar.
 * @param patron Patrón a buscar.
 * @return Par que indica si fue encontrado y su posición (1-based).
 */
pair<bool, size_t> buscar_patron_con_posicion(const string& texto, const string& patron) {
    size_t pos = texto.find(patron);
    if (pos == string::npos) {
        return {false, 0};
    }
    return {true, pos + 1};
}

/**
 * @brief Expande un posible palíndromo desde el centro.
 * @param s Cadena original.
 * @param left Índice izquierdo.
 * @param right Índice derecho.
 * @param max_len Longitud máxima actual.
 * @param start Índice inicial del palíndromo.
 */
void expandir_desde_centro(const string& s, size_t left, size_t right, size_t& max_len, size_t& start) {
    size_t n = s.length();
    while (left < n && right < n && s[left] == s[right]) {
        size_t longitud_actual = right - left + 1;
        if (longitud_actual > max_len) {
            max_len = longitud_actual;
            start = left;
        }
        if (left == 0) break;
        left--;
        right++;
    }
}

/**
 * @brief Encuentra el palíndromo más largo dentro de una cadena de texto.
 * @param s Cadena a analizar.
 * @return Par con las posiciones (1-based) y el palíndromo encontrado.
 */
pair<pair<size_t, size_t>, string> encontrar_palindromo_real(const string& s) {
    size_t n = s.length();
    if (n == 0) {
        return {{0, 0}, ""};
    }

    size_t max_len = 1;
    size_t start = 0;

    for (size_t i = 0; i < n; i++) {
        expandir_desde_centro(s, i, i, max_len, start);       // Palíndromo impar
        expandir_desde_centro(s, i, i + 1, max_len, start);   // Palíndromo par
    }

    string palindromo = s.substr(start, max_len);
    size_t pos_final = start + max_len;
    return {{start + 1, pos_final}, palindromo};
}

/**
 * @brief Encuentra el substring común más largo entre dos cadenas.
 * @param s1 Primera cadena.
 * @param s2 Segunda cadena.
 * @return Par con las posiciones (1-based) y el substring común más largo.
 */
pair<pair<size_t, size_t>, string> encontrar_substring_comun_real(const string& s1, const string& s2) {
    size_t m = s1.length();
    size_t n = s2.length();

    vector<vector<size_t>> dp(m + 1, vector<size_t>(n + 1, 0));

    size_t max_len = 0;
    size_t end = 0;

    for (size_t i = 1; i <= m; i++) {
        for (size_t j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > max_len) {
                    max_len = dp[i][j];
                    end = i;
                }
            }
        }
    }

    if (max_len == 0) {
        return {{0, 0}, ""};
    }

    string substring = s1.substr(end - max_len, max_len);
    return {{end - max_len + 1, end}, substring};
}

#endif // TEXT_ANALYSIS_H
