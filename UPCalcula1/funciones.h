#pragma once
#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <string>
#include <vector>
#include "conjunto.h"
#include "helpers.h"

namespace Funciones {
	using productoPair = std::vector<std::pair<std::string, std::string>>;

	inline productoPair calcularProdCartesiano(std::vector< std::vector<std::string>> conjunto) {
		productoPair resultado;
		size_t n = conjunto.size();
		for (int i = 0; i < n; i++) {
			std::string c1 = conjunto[i].size() > 1 ? vectorToCString(conjunto[i]) : conjunto[i][0];
			for (int j = 0; j < n; j++) {
				std::string c2 = conjunto[i].size() > 1 ? vectorToCString(conjunto[j]) : conjunto[j][0];
				resultado.push_back(std::make_pair(c1, c2));
			}
		}
		return resultado;
	}

	Conjunto parseConjunto(std::string conjunto_raw) {
		Conjunto conjunto = Conjunto(conjunto_raw);
		conjunto.parse();
		return conjunto;
	}

};
#endif