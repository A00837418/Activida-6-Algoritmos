#ifndef TEXT_ANALYSIS_H
#define TEXT_ANALYSIS_H

#include <string>
#include <utility>

using namespace std;

string leerarchivo(const string& ruta);

pair<bool, size_t> buscarpatronconposicion(const string& texto, const string& patron);

pair<pair<size_t, size_t>, string> encontrarpalindromoreal(const string& s);

pair<pair<size_t, size_t>, string> encontrarsubstringcomunreal(const string& s1, const string& s2);

#endif 