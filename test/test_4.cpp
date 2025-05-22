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

TEST(ArchivoTest, ArchivoInexistente) {
    string contenido = leer_archivo("archivo_que_no_existe.txt");
    EXPECT_EQ(contenido, "");
}

// 🔹 Test 2: El archivo existe y contiene texto → cubre líneas (1), (5), (6), (7)
TEST(ArchivoTest, ArchivoExistenteConContenido) {
    string ruta = "temp_test_file.txt";
    ofstream archivo(ruta);
    archivo << "Hola\nMundo\r\nC++";
    archivo.close();

    string contenido = leer_archivo(ruta);
    // Verifica que \r fue eliminado
    EXPECT_EQ(contenido, "Hola\nMundo\nC++");

    remove(ruta.c_str());  // Limpieza
}

// 🔹 Test 3: Archivo vacío → cubre que se puede leer archivo válido sin contenido
TEST(ArchivoTest, ArchivoVacio) {
    string ruta = "archivo_vacio.txt";
    ofstream archivo(ruta);
    archivo.close();

    string contenido = leer_archivo(ruta);
    EXPECT_EQ(contenido, "");

    remove(ruta.c_str());
}