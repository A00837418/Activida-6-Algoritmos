
#include "text_analysis.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <stdexcept>  

// Lee un archivo de texto y devuelve su contenido como una cadena
std::string leer_archivo(const std::string& ruta) {
    std::ifstream archivo(ruta);
    if (!archivo.is_open()) {
        throw std::runtime_error("No se pudo abrir el archivo: " + ruta);
    }

    std::stringstream buffer;
    buffer << archivo.rdbuf();
    return buffer.str();
}

// Busca un patrón en un texto y devuelve si se encontró y la posición
std::pair<bool, size_t> buscar_patron_con_posicion(const std::string& texto, const std::string& patron) {
    size_t pos = texto.find(patron);
    return {pos != std::string::npos, pos};
}

// Función auxiliar para expandir desde el centro y encontrar la longitud máxima de palíndromo
size_t expandir_palindromo(const std::string& s, size_t izquierda, size_t derecha, size_t& inicio) {
    size_t n = s.size();
    while (izquierda < n && derecha < n && izquierda <= derecha && s[izquierda] == s[derecha]) {
        if (izquierda == 0) break;
        --izquierda;
        ++derecha;
    }

    // Ajustar límites tras salir del bucle
    if (s[izquierda] != s[derecha]) {
        ++izquierda;
        --derecha;
    }

    size_t len = derecha - izquierda + 1;
    if (len > 0) {
        inicio = izquierda;
    }
    return len;
}

// Encuentra el palíndromo más largo real dentro de una cadena y su posición
std::pair<std::pair<size_t, size_t>, std::string> encontrar_palindromo_real(const std::string& s) {
    size_t n = s.size();
    size_t inicio = 0, max_len = 0;

    for (size_t i = 0; i < n; ++i) {
        size_t temp_inicio = 0;

        size_t len1 = expandir_palindromo(s, i, i, temp_inicio);
        if (len1 > max_len) {
            max_len = len1;
            inicio = temp_inicio;
        }

        len1 = expandir_palindromo(s, i, i + 1, temp_inicio);
        if (len1 > max_len) {
            max_len = len1;
            inicio = temp_inicio;
        }
    }

    std::string candidato = s.substr(inicio, max_len);

    // Eliminar espacios al principio y final
    size_t real_start_offset = candidato.find_first_not_of(' ');
    size_t real_end_offset = candidato.find_last_not_of(' ');

    if (real_start_offset == std::string::npos || real_end_offset == std::string::npos) {
        return {{0, 0}, ""};
    }

    size_t adjusted_start = inicio + real_start_offset;
    size_t adjusted_end = inicio + real_end_offset;
    std::string palindromo_limpio = s.substr(adjusted_start, adjusted_end - adjusted_start + 1);

    return {{adjusted_start, adjusted_end}, palindromo_limpio};
}

// Encuentra la subcadena común más larga entre dos cadenas y su posición
std::pair<std::pair<size_t, size_t>, std::string> encontrar_substring_comun_real(const std::string& s1, const std::string& s2) {
    size_t m = s1.size(), n = s2.size();
    size_t max_len = 0, end_index_s1 = 0;
    std::vector<std::vector<size_t>> dp(m + 1, std::vector<size_t>(n + 1, 0));

    for (size_t i = 1; i <= m; ++i) {
        for (size_t j = 1; j <= n; ++j) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > max_len) {
                    max_len = dp[i][j];
                    end_index_s1 = i;
                }
            }
        }
    }

    std::string common_substring = s1.substr(end_index_s1 - max_len, max_len);
    return {{end_index_s1 - max_len, end_index_s1 - 1}, common_substring};
}
