#pragma once
#include <string>
#include <vector>
#include "conjunto.h"

namespace Funciones2 {
    inline std::vector<std::pair<std::string, std::string>> calcularProdCartesiano(std::vector<std::string> conjunto) {
        std::vector<std::pair<std::string, std::string>> resultado;
        // (1, "a", 0.1)
        //make_pair(1, "a", 0.1);
        int n = conjunto.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                resultado.push_back(std::make_pair(conjunto[i], conjunto[j]));
            }
        }
        return resultado;
    }

    inline Conjunto2 parseConjunto(std::string conjunto_raw) {
        Conjunto2 conjunto = Conjunto2(conjunto_raw);
        conjunto.parse();
        return conjunto;
    }

};

