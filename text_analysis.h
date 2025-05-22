

// texxt_analysis.h

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
#ifndef TEXT_ANALYSIS_H
#define TEXT_ANALYSIS_H

#include <string>
#include <utility>

/**
 * @brief Lee el contenido de un archivo de texto.
 * @param ruta Ruta del archivo a leer.
 * @return Contenido completo del archivo como una cadena.
 */
std::string leer_archivo(const std::string& ruta);

/**
 * @brief Busca un patrón dentro de un texto.
 * @param texto Texto donde buscar.
 * @param patron Patrón a buscar.
 * @return Par que indica si fue encontrado y su posición (1-based).
 */
std::pair<bool, size_t> buscar_patron_con_posicion(const std::string& texto, const std::string& patron);

/**
 * @brief Encuentra el palíndromo más largo dentro de una cadena de texto.
 * @param s Cadena a analizar.
 * @return Par con las posiciones (1-based) y el palíndromo encontrado.
 */
std::pair<std::pair<size_t, size_t>, std::string> encontrar_palindromo_real(const std::string& s);

/**
 * @brief Encuentra el substring común más largo entre dos cadenas.
 * @param s1 Primera cadena.
 * @param s2 Segunda cadena.
 * @return Par con las posiciones (1-based) y el substring común más largo.
 */
std::pair<std::pair<size_t, size_t>, std::string> encontrar_substring_comun_real(const std::string& s1, const std::string& s2);

#endif // TEXT_ANALYSIS_H
