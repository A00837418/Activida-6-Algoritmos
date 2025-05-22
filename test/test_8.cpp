#include <gtest/gtest.h>
#include "text_analysis.h"

pair<bool, size_t> buscar_patron_con_posicion(const string& texto, const string& patron) {
    size_t pos = texto.find(patron);
    if (pos == string::npos) {
Uncovered code
        return {false, 0};
    }
    return {true, pos + 1};
}