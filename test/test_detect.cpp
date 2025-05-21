// test/test_detect.cpp
#include <gtest/gtest.h>

// Declara la función que vas a probar (puede venir de main.cpp o header)
bool contieneMalicioso(const std::string& linea);

// Pruebas
TEST(DeteccionMalwareTest, DetectaMalware) {
    EXPECT_TRUE(contieneMalicioso("Este archivo contiene malware"));
}

TEST(DeteccionMalwareTest, NoDetectaTextoInocente) {
    EXPECT_FALSE(contieneMalicioso("Este archivo es seguro"));
}
