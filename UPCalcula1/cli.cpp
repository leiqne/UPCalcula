#include "funciones.h"
#include <vector>
#include <iostream>
#include <Windows.h>

using namespace std;

int main(int argc, char* argv[]) {
	LARGE_INTEGER frequency;
	LARGE_INTEGER start;
	LARGE_INTEGER end;

	QueryPerformanceFrequency(&frequency);
	QueryPerformanceCounter(&start);

	vector<string> args;
	for (int i = 1; i < argc; i++) args.push_back(argv[i]);

	if (argc < 2) {
		cout << "Error";
		return EXIT_FAILURE;
	}

	if (args.at(0) == "prod") {
		Conjunto conjunto_parse = Funciones::parseConjunto(args.at(1));
		cout << "conjunto: " << conjunto_parse << endl;

		auto resultado = Funciones::calcularProdCartesiano(conjunto_parse);
		for (auto elemento = resultado.begin(); elemento != resultado.end(); ++elemento) {
			cout << "(" << elemento->first << ", " << elemento->second << ")" << (
				elemento + 1 != resultado.end() && (elemento + 1)->first != elemento->first ? "\n" : " "
				);
		}
	}
	else if (args.at(0) == "test") {
		string conjunto_raw = args.size() > 1 ? args.at(1) : "(3,9,0)";
		cout << "Conjunto de entrada: " << conjunto_raw << endl;
		Conjunto conjunto = Funciones::parseConjunto(conjunto_raw);
		cout << "size:" << conjunto.size() << endl << "Conjunto parseado:" << conjunto << endl;
		Conjunto R = Funciones::parseConjunto("(1,3),(3,1),(2,0),(0,2)");
		cout << "R: " << R << endl;

		vector<tiposRelacion> relaciones = conjunto.clasificarR(R);
		for (auto relacion : relaciones) cout << tipos[relacion] << endl;

		QueryPerformanceCounter(&end);
		double elapsed = static_cast<double>(end.QuadPart - start.QuadPart) / frequency.QuadPart;
		cout << endl << "El programa tardo " << elapsed << " milisegundos en ejecutarse." << endl;
	}

	return 0;
}