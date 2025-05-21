
#ifndef TEXT_ANALYSIS_H
#define TEXT_ANALYSIS_H

#include <string>
#include <utility>

// Lee el contenido de un archivo y lo retorna como una cadena
std::string leer_archivo(const std::string& ruta);

// Busca un patrón en un texto y retorna si fue encontrado y su posición
std::pair<bool, std::size_t> buscar_patron_con_posicion(const std::string& texto, const std::string& patron);

// Encuentra el palíndromo más largo dentro del texto y devuelve su posición y contenido
std::pair<std::pair<std::size_t, std::size_t>, std::string> encontrar_palindromo_real(const std::string& s);

// Encuentra la subcadena común más larga entre dos textos y devuelve su posición y contenido
std::pair<std::pair<std::size_t, std::size_t>, std::string> encontrar_substring_comun_real(const std::string& s1, const std::string& s2);

#endif // TEXT_ANALYSIS_H
