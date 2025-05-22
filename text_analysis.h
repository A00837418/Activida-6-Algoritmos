
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
#include <iostream>

using namespace std;

string leer_archivo(const string& ruta);

pair<bool, size_t> buscar_patron_con_posicion(const string& texto, const string& patron);

void expandir_desde_centro(const string& s, size_t left, size_t right, size_t& max_len, size_t& start);

pair<pair<size_t, size_t>, string> encontrar_palindromo_real(const string& s);

pair<pair<size_t, size_t>, string> encontrar_substring_comun_real(const string& s1, const string& s2);

#endif