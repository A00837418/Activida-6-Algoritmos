
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

 #include "text_analysis.h"

string leer_archivo(const string& ruta) {
    ifstream archivo(ruta);
    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo: " << ruta << endl;
        return "";
    }
    string contenido((istreambuf_iterator<char>(archivo)), istreambuf_iterator<char>());
    contenido.erase(remove(contenido.begin(), contenido.end(), '\r'), contenido.end());
    return contenido;
}

pair<bool, size_t> buscar_patron_con_posicion(const string& texto, const string& patron) {
    size_t pos = texto.find(patron);
    if (pos == string::npos) {
        return {false, 0};
    }
    return {true, pos + 1};
}

void expandir_desde_centro(const string& s, size_t izquierda, size_t derecha, size_t& longitud_maxima, size_t& inicio) {
    size_t n = s.length();
    while (izquierda < n && derecha < n && s[izquierda] == s[derecha]) {
        size_t longitud_actual = derecha - izquierda + 1;
        if (longitud_actual > longitud_maxima) {
            longitud_maxima = longitud_actual;
            inicio = izquierda;
        }
        if (izquierda == 0) {
            break;
        }
        izquierda--;
        derecha++;
    }
}

pair<pair<size_t, size_t>, string> encontrar_palindromo_real(const string& s) {
    size_t n = s.length();
    if (n == 0) {
        return {{0, 0}, ""};
    }
    size_t longitud_maxima = 1;
    size_t inicio = 0;
    for (size_t i = 0; i < n; i++) {
        expandir_desde_centro(s, i, i, longitud_maxima, inicio);       // Palíndromo impar
        if (i + 1 < n) {
            expandir_desde_centro(s, i, i + 1, longitud_maxima, inicio);   // Palíndromo par
        }
    }
    string palindromo = s.substr(inicio, longitud_maxima);
    size_t pos_final = inicio + longitud_maxima;
    return {{inicio + 1, pos_final}, palindromo};
}

pair<pair<size_t, size_t>, string> encontrar_subcadena_comun_real(const string& s1, const string& s2) {
    size_t m = s1.length();
    size_t n = s2.length();
    vector<vector<size_t>> dp(m + 1, vector<size_t>(n + 1, 0));
    size_t longitud_maxima = 0;
    size_t fin = 0;
    for (size_t i = 1; i <= m; i++) {
        for (size_t j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > longitud_maxima) {
                    longitud_maxima = dp[i][j];
                    fin = i;
                }
            }
        }
    }
    if (longitud_maxima == 0) {
        return {{0, 0}, ""};
    }
    string subcadena = s1.substr(fin - longitud_maxima, longitud_maxima);
    return {{fin - longitud_maxima + 1, fin}, subcadena};
}
