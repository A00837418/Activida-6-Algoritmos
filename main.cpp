#include <iostream>
#include <string>
#include <algorithm>
#include <stdexcept>
#include "text_analysis.h"

int main() {
    try {
        std::string t1 = leer_archivo("Textos/transmission1.txt");
        std::string t2 = leer_archivo("Textos/transmission2.txt");
        std::string m1 = leer_archivo("Textos/mcode1.txt");
        std::string m2 = leer_archivo("Textos/mcode2.txt");
        std::string m3 = leer_archivo("Textos/mcode3.txt");

        std::cout << "Parte 1:" << std::endl;

        std::pair<std::string, std::string> transmisiones[] = {
            {t1, m1}, {t1, m2}, {t1, m3},
            {t2, m1}, {t2, m2}, {t2, m3}
        };

        for (const auto& [transmision, malware] : transmisiones) {
            auto [found, pos] = buscar_patron_con_posicion(transmision, malware);
            std::cout << (found ? "true " + std::to_string(pos) : "false") << std::endl;
        }

        std::cout << "Parte 2:" << std::endl;

        auto [pal1_pos, pal1_str] = encontrar_palindromo_real(t1);
        std::replace(pal1_str.begin(), pal1_str.end(), '\n', ' ');
        std::cout << pal1_pos.first << " " << pal1_pos.second << " " << pal1_str << std::endl;

        auto [pal2_pos, pal2_str] = encontrar_palindromo_real(t2);
        std::replace(pal2_str.begin(), pal2_str.end(), '\n', ' ');
        std::cout << pal2_pos.first << " " << pal2_pos.second << " " << pal2_str << std::endl;

        std::cout << "Parte 3:" << std::endl;
        auto [sub_pos, sub_str] = encontrar_substring_comun_real(t1, t2);
        std::cout << sub_pos.first << " " << sub_pos.second << " " << sub_str << std::endl;

        return 0;

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
}
