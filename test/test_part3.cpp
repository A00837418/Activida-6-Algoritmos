#include <gtest/gtest.h>
#include <string>
#include <utility> 
#include <limits>   

using namespace std;

// Declaración o inclusión de la función que pruebas
// pair<size_t, size_t> buscarSubstringComun(const string& s1, const string& s2);

TEST(SubstringComunTest, SubstringComunValido) {
    string s1 = "abcdef";
    string s2 = "zabcxy";

    auto pos = buscarSubstringComun(s1, s2);
    EXPECT_EQ(pos.first, 1);
    EXPECT_EQ(pos.second, 4);
}

TEST(SubstringComunTest, NoSubstringComun) {
    string s1 = "abc";
    string s2 = "xyz";

    auto pos = buscarSubstringComun(s1, s2);
    EXPECT_EQ(pos.first, string::npos);
    EXPECT_EQ(pos.second, string::npos);
}
