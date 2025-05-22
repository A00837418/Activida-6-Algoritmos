#include <gtest/gtest.h>
#include <fstream>
#include "text_analysis.h"

// Función auxiliar para crear archivos temporales
void crear_archivo_temporal(const std::string& nombre, const std::string& contenido) {
    std::ofstream archivo(nombre);
    archivo << contenido;
    archivo.close();
}

// Test para leer_archivo
TEST(TextAnalysisTest, LeerArchivoValido) {
    std::string nombre = "temp.txt";
    std::string contenido = "Hola mundo";
    crear_archivo_temporal(nombre, contenido);

    std::string leido = leer_archivo(nombre);
    EXPECT_EQ(leido, contenido);
    remove(nombre.c_str()); // Limpieza
}

TEST(TextAnalysisTest, LeerArchivoInexistente) {
    std::string leido = leer_archivo("no_existe.txt");
    EXPECT_EQ(leido, "");
}