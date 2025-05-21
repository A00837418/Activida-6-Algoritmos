#ifndef TEXT_ANALYSIS_H
#define TEXT_ANALYSIS_H

#include <string>
#include <utility>

using namespace std;

// Lee todo el contenido de un archivo dado su ruta
string leerArchivo(const string& ruta);

// Busca un patrón en un texto; devuelve si se encontró y la posición
pair<bool, size_t> buscarPatronConPosicion(const string& texto, const string& patron);

// Encuentra el palíndromo más largo en una cadena; devuelve posición y subcadena
pair<pair<size_t, size_t>, string> encontrarPalindromoReal(const string& s);

// Encuentra la subcadena común más larga entre dos cadenas; devuelve posición y subcadena
pair<pair<size_t, size_t>, string> encontrarSubstringComunReal(const string& s1, const string& s2);

#endif
