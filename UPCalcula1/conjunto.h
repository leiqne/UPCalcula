#pragma once
#ifndef CONJUNTO_H
#define CONJUNTO_H
#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <sstream>

using elementosType = std::vector<std::string>;
using conjuntoType = std::vector<elementosType>;

class Conjunto2
{
public:

    Conjunto2() = default;
    Conjunto2(std::string);
    conjuntoType parse();
    conjuntoType getConjunto2();
    friend std::ostream& operator<<(std::ostream& os, const Conjunto2& conjunto);
    ~Conjunto2() = default;

private:
    std::string conjunto_raw;
    conjuntoType conjunto;
};

inline Conjunto2::Conjunto2(std::string conjunto_raw_) : conjunto_raw(conjunto_raw_) {}

conjuntoType Conjunto2::parse() {
    conjunto.clear();
    std::regex re("\\(((?:\\w+,)*\\w+)\\)");

    // Iteramos sobre todas las coincidencias encontradas en conjunto_raw
    auto begin = std::sregex_iterator(conjunto_raw.begin(), conjunto_raw.end(), re);
    auto end = std::sregex_iterator();

    for (std::sregex_iterator i = begin; i != end; ++i) {
        std::smatch match = *i;

        // Creamos una expresión regular para capturar los valores separados por comas dentro de los paréntesis
        std::regex re2("\\w+");

        // Iteramos sobre todas las coincidencias encontradas dentro de los paréntesis
        auto begin2 = std::sregex_iterator(match[1].first, match[1].second, re2);
        auto end2 = std::sregex_iterator();
        elementosType elementos;

        for (std::sregex_iterator j = begin2; j != end2; ++j) {
            std::smatch match2 = *j;

            // Convertimos los valores separados por comas a los tipos de dato necesarios
            std::stringstream ss1(match2.str());
            std::string val;
            ss1 >> val;
            elementos.push_back(val);
        }

        // Agregamos los valores al vector de elementos
        conjunto.emplace_back(elementos);
    }
    return conjunto;
}

std::ostream& operator<<(std::ostream& os, const Conjunto2& conjunto) {
    os << "{ ";
    for (const auto& conjunto : conjunto.conjunto) {
        os << "(";
        for (auto elemento = conjunto.begin(); elemento != conjunto.end(); ++elemento)
            os << *elemento << (elemento + 1 == conjunto.end() ? "" : ",");
        os << ") ";
    }
    os << "}";
    return os;
}

conjuntoType Conjunto2::getConjunto2() { return conjunto; }

#endif 

