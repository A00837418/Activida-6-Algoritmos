
#ifndef TEXT_ANALYSIS_H
#define TEXT_ANALYSIS_H

#include <string>
#include <utility>

using namespace std;

string leerArchivo(const string& ruta);

pair<bool, size_t> buscar_patron_con_posicion(const string& texto, const string& patron);

pair<pair<size_t, size_t>, string> encontrar_palindromo_real(const string& s);

pair<pair<size_t, size_t>, string> encontrar_substring_comun_real(const string& s1, const string& s2);

#endif
