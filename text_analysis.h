
#ifndef TEXT_ANALYSIS_H
#define TEXT_ANALYSIS_H

#include <string>
#include <utility>

std::string leer_archivo(const std::string& ruta);
std::pair<bool, size_t> buscar_patron_con_posicion(const std::string& texto, const std::string& patron);
std::pair<std::pair<size_t, size_t>, std::string> encontrar_palindromo_real(const std::string& s);
std::pair<std::pair<size_t, size_t>, std::string> encontrar_substring_comun_real(const std::string& s1, const std::string& s2);

#endif // TEXT_ANALYSIS_H
