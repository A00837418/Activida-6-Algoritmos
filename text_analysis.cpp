#include "text_analysis.h"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

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

pair<bool, size_t> buscar_patron_con_posicion(const string& texto, const string& patron) {
    size_t pos = texto.find(patron);
    if (pos == string::npos) {
        return {false, 0};
    }
    return {true, pos + 1};
}

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

pair<pair<size_t, size_t>, string> encontrar_palindromo_real(const string& s) {
    size_t n = s.length();
    if (n == 0) return {{0, 0}, ""};

    size_t max_len = 1;
    size_t start = 0;

    for (size_t i = 0; i < n; i++) {
        expandir_desde_centro(s, i, i, max_len, start);       // Odd
        expandir_desde_centro(s, i, i + 1, max_len, start);   // Even
    }

    string palindromo = s.substr(start, max_len);
    size_t pos_final = start + max_len;
    return {{start + 1, pos_final}, palindromo};
}

pair<pair<size_t, size_t>, string> encontrar_substring_comun_real(const string& s1, const string& s2) {
    size_t m = s1.length(), n = s2.length();
    vector<vector<size_t>> dp(m + 1, vector<size_t>(n + 1, 0));

    size_t max_len = 0, end = 0;
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

    if (max_len == 0) return {{0, 0}, ""};

    string substring = s1.substr(end - max_len, max_len);
    return {{end - max_len + 1, end}, substring};
}
