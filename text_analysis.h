
/*
 * SonarQube, open source software quality management tool.
 * Copyright (C) 2008-2013 SonarSource
 * http://github.com/SonarOpenCommunity/sonar-cxx
 *
 * SonarQube is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3 of the License, or (at your option) any later version.
 *
 * SonarQube is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#ifndef TEXT_ANALYSIS_H
#define TEXT_ANALYSIS_H

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

string leerArchivo(const string& ruta) {
    ifstream archivo(ruta);
    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo: " << ruta << endl;
        return "";
    }
    string contenido((istreambuf_iterator<char>(archivo)), istreambuf_iterator<char>());
    contenido.erase(remove(contenido.begin(), contenido.end(), '\r'), contenido.end());
    return contenido;
}

pair<bool, size_t> buscarPatronConPosicion(const string& texto, const string& patron) {
    size_t pos = texto.find(patron);
    if (pos == string::npos) return {false, 0};
    return {true, pos + 1}; // 1-based
}

pair<pair<size_t, size_t>, string> encontrarPalindromoReal(const string& s) {
    size_t n = s.length();
    if (n == 0) return {{0, 0}, ""};

    size_t max_len = 1;
    size_t start = 0;

    for (size_t i = 0; i < n; i++) {
        size_t l = i, r = i;
        while (l <= r && r < n && s[l] == s[r]) {
            if (r - l + 1 > max_len) {
                max_len = r - l + 1;
                start = l;
            }
            if (l == 0) break;
            l--;
            r++;
        }

        l = i;
        r = i + 1;
        while (l <= r && r < n && s[l] == s[r]) {
            if (r - l + 1 > max_len) {
                max_len = r - l + 1;
                start = l;
            }
            if (l == 0) break;
            l--;
            r++;
        }
    }

    string palindromo = s.substr(start, max_len);
    size_t pos_final = start + max_len;
    return {{start + 1, pos_final}, palindromo};
}

pair<pair<size_t, size_t>, string> encontrarSubstringComunReal(const string& s1, const string& s2) {
    size_t m = s1.length();
    size_t n = s2.length();
    vector<vector<size_t>> dp(m + 1, vector<size_t>(n + 1, 0));
    size_t max_len = 0;
    size_t end = 0;

    for (size_t i = 1; i <= m; i++) {
        for (size_t j = 1; j <= n; j++) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
                if (dp[i][j] > max_len) {
                    max_len = dp[i][j];
                    end = i;
                }
            }
        }
    }

    if (max_len == 0) return {{0, 0}, ""};

    string substring = s1.substr(end - max_len, max_len);
    return {{end - max_len + 1, end}, substring};
}

#endif // TEXT_ANALYSIS_H
