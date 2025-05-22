
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

#ifndef ANALISIS_DE_TEXTO_H
#define ANALISIS_DE_TEXTO_H

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
string leer_archivo(const string& ruta);

/**
 * @brief Busca un patrón dentro de un texto.
 * @param texto Texto donde buscar.
 * @param patron Patrón a buscar.
 * @return Par que indica si fue encontrado y su posición (1-based).
 */
pair<bool, size_t> buscar_patron_con_posicion(const string& texto, const string& patron);

/**
 * @brief Expande un posible palíndromo desde el centro.
 * @param s Cadena original.
 * @param izquierda Índice izquierdo.
 * @param derecha Índice derecho.
 * @param longitud_maxima Longitud máxima actual.
 * @param inicio Índice inicial del palíndromo.
 */
void expandir_desde_centro(const string& s, size_t izquierda, size_t derecha, size_t& longitud_maxima, size_t& inicio);

/**
 * @brief Encuentra el palíndromo más largo dentro de una cadena de texto.
 * @param s Cadena a analizar.
 * @return Par con las posiciones (1-based) y el palíndromo encontrado.
 */
pair<pair<size_t, size_t>, string> encontrar_palindromo_real(const string& s);

/**
 * @brief Encuentra la subcadena común más larga entre dos cadenas.
 * @param s1 Primera cadena.
 * @param s2 Segunda cadena.
 * @return Par con las posiciones (basadas en 1) y la subcadena común más larga.
 */
pair<pair<size_t, size_t>, string> encontrar_subcadena_comun_real(const string& s1, const string& s2);

#endif // ANALISIS_DE_TEXTO_H
