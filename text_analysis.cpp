#include "text_analysis.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

string leerarchivo(const string& ruta) {
    ifstream archivo(ruta);
    stringstream buffer;
    buffer << archivo.rdbuf();
    return buffer.str();
}

pair<bool, size_t> buscarpatronconposicion(const string& texto, const string& patron) {
    size_t pos = texto.find(patron);
    return {pos != string::npos, pos};
}

pair<pair<size_t, size_t>, string> encontrarpalindromoreal(const string& s) {
    size_t n = s.size();
    size_t start = 0, maxLen = 0;

    for (size_t i = 0; i < n; ++i) {
        size_t l = i, r = i;
        while (l < n && r < n && l <= r && s[l] == s[r]) {
            if (r - l + 1 > maxLen) {
                start = l;
                maxLen = r - l + 1;
            }
            if (l == 0) break;
            --l;
            ++r;
        }

        l = i, r = i + 1;
        while (l < n && r < n && l <= r && s[l] == s[r]) {
            if (r - l + 1 > maxLen) {
                start = l;
                maxLen = r - l + 1;
            }
            if (l == 0) break;
            --l;
            ++r;
        }
    }

    string candidato = s.substr(start, maxLen);

    // Eliminar espacios al principio y final del palíndromo
    size_t realStartOffset = candidato.find_first_not_of(' ');
    size_t realEndOffset = candidato.find_last_not_of(' ');

    if (realStartOffset == string::npos || realEndOffset == string::npos) {
        return {{0, 0}, ""};
    }

    size_t adjustedStart = start + realStartOffset;
    size_t adjustedEnd = start + realEndOffset;
    string palindromoLimpio = s.substr(adjustedStart, adjustedEnd - adjustedStart + 1);

    return {{adjustedStart, adjustedEnd}, palindromoLimpio};
}

pair<pair<size_t, size_t>, string> encontrarsubstringcomunreal(const string& s1, const string& s2) {
    size_t m = s1.size(), n = s2.size();
    size_t maxLen = 0, endIndexS1 = 0;
    vector<vector<size_t>> dp(m + 1, vector<size_t>(n + 1, 0));

    for (size_t i = 1; i <= m; ++i) {
        for (size_t j = 1; j <= n; ++j) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > maxLen) {
                    maxLen = dp[i][j];
                    endIndexS1 = i;
                }
            }
        }
    }

    string commonSubstring = s1.substr(endIndexS1 - maxLen, maxLen);
    return {{endIndexS1 - maxLen, endIndexS1 - 1}, commonSubstring};
} 