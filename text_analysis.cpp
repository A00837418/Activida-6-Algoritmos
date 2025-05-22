#include "text_analysis.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

std::string leer_archivo(const std::string& ruta) {
    std::ifstream archivo(ruta);
    if (!archivo.is_open()) {
        std::cerr << "No se pudo abrir el archivo: " << ruta << std::endl;
        return "";
    }
    std::string contenido((std::istreambuf_iterator<char>(archivo)), std::istreambuf_iterator<char>());
    contenido.erase(std::remove(contenido.begin(), contenido.end(), '\r'), contenido.end());
    return contenido;
}

std::pair<bool, size_t> buscar_patron_con_posicion(const std::string& texto, const std::string& patron) {
    size_t pos = texto.find(patron);
    if (pos == std::string::npos) {
        return {false, 0};
    }
    return {true, pos + 1}; // posición 1-based
}

void expandir_desde_centro(const std::string& s, size_t left, size_t right, size_t& max_len, size_t& start) {
    size_t n = s.length();
    while (left < n && right < n && s[left] == s[right]) {
        size_t longitud_actual = right - left + 1;
        if (longitud_actual > max_len) {
            max_len = longitud_actual;
            start = left;
        }
        if (left == 0) {
            break;
        }
        left--;
        right++;
    }
}

std::pair<std::pair<size_t, size_t>, std::string> encontrar_palindromo_real(const std::string& s) {
    size_t n = s.length();
    if (n == 0) {
        return {{0, 0}, ""};
    }

    size_t max_len = 1;
    size_t start = 0;

    for (size_t i = 0; i < n; ++i) {
        expandir_desde_centro(s, i, i, max_len, start);       // Palíndromo impar
        expandir_desde_centro(s, i, i + 1, max_len, start);   // Palíndromo par
    }

    std::string palindromo = s.substr(start, max_len);
    size_t pos_final = start + max_len;
    return {{start + 1, pos_final}, palindromo};
}

std::pair<std::pair<size_t, size_t>, std::string> encontrar_substring_comun_real(const std::string& s1, const std::string& s2) {
    size_t m = s1.length();
    size_t n = s2.length();

    std::vector<std::vector<size_t>> dp(m + 1, std::vector<size_t>(n + 1, 0));

    size_t max_len = 0;
    size_t end = 0;

    for (size_t i = 1; i <= m; ++i) {
        for (size_t j = 1; j <= n; ++j) {
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

    std::string substring = s1.substr(end - max_len, max_len);
    return {{end - max_len + 1, end}, substring};
}
