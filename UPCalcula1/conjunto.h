#pragma once

#ifndef CONJUNTO_H
#define CONJUNTO_H
#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <sstream>
#include <map>

using elementosType = std::vector<std::string>;
using conjuntoType = std::vector<elementosType>;
using elementoPair = std::pair<std::string, std::string>;
using conjuntoPair = std::vector<elementoPair>;

enum tiposRelacion { REFLEXIVA, IRREFLEXIVA, SIMETRICA, ASIMETRICA, ANTISIMETRICA, TRANSITIVA, EQUIVALENCIA, ORDEN_PARCIAL };

std::map<tiposRelacion, std::string> tipos = {
    {tiposRelacion::REFLEXIVA, "Reflexiva"},
    {tiposRelacion::IRREFLEXIVA, "Irreflexiva"},
    {tiposRelacion::SIMETRICA, "Simetrica"},
    {tiposRelacion::ASIMETRICA, "Asimetrica"},
    {tiposRelacion::ANTISIMETRICA, "Antisimetrica"},
    {tiposRelacion::TRANSITIVA, "Transitiva"},
    {tiposRelacion::EQUIVALENCIA, "Equivalencia"},
    {tiposRelacion::ORDEN_PARCIAL, "Orden parcial"}
};

class Conjunto
{
public:

    Conjunto() = default;
    Conjunto(std::string);
    Conjunto(conjuntoType);
    inline Conjunto pairToConjunto(conjuntoPair pair);
    conjuntoType parse();
    conjuntoType getConjunto();
    std::vector<tiposRelacion> clasificarR(Conjunto&);

    size_t size();

    bool include(std::pair<std::string, std::string>);
    Conjunto conjuntoCociente(Conjunto&);
    conjuntoType::iterator begin();
    conjuntoType::iterator end();

    friend std::ostream& operator<<(std::ostream& os, const Conjunto& conjunto);
    operator conjuntoType() const;
    void push_back(std::string elemento);
    ~Conjunto() = default;

private:
    std::string conjunto_raw;
    conjuntoType conjunto;// 1 , 2 , 3 , 4 , 5
    bool esSimetrica(Conjunto&);
    bool esAsimetrica(Conjunto&);
    bool esEquivalente(Conjunto&);
    bool esAntisimetrica(Conjunto&);
    bool esReflexiva(Conjunto&);
    bool esTransitiva(Conjunto&);
    bool esIrreflexiva(Conjunto&);
    bool esOrdenParcial(Conjunto&);

    bool es_asimetrica = false, es_reflexiva = false, es_simetrica = false;
};

Conjunto::Conjunto(std::string conjunto_raw_) : conjunto_raw(conjunto_raw_) {}

Conjunto::Conjunto(conjuntoType conjunto_) : conjunto(conjunto_) {}

Conjunto Conjunto::pairToConjunto(conjuntoPair conjunto_pair) {
    conjunto.clear();
    for (auto elemento : conjunto_pair) {
        conjunto.push_back({ elemento.first, elemento.second });
    }
    return conjunto;
}

conjuntoType Conjunto::parse() {
    conjunto.clear();
    std::regex re("\\(((?:\\w+,)*\\w+)\\)");

    // Iteramos sobre todas las coincidencias encontradas en conjunto_raw
    auto begin = std::sregex_iterator(conjunto_raw.begin(), conjunto_raw.end(), re);
    auto end = std::sregex_iterator();

    // Verificamos si el conjunto contiene un solo elemento o más
    if (std::distance(begin, end) == 1) {
        std::smatch match = *begin;
        std::regex re2("\\w+");

        // Iteramos sobre todas las coincidencias encontradas dentro del único conjunto
        auto begin2 = std::sregex_iterator(match[1].first, match[1].second, re2);
        auto end2 = std::sregex_iterator();

        // Creamos un vector para cada valor separado por comas dentro del conjunto
        for (std::sregex_iterator j = begin2; j != end2; ++j) {
            std::smatch match2 = *j;
            std::vector<std::string> elementos;
            std::stringstream ss1(match2.str());
            std::string val;
            ss1 >> val;
            elementos.push_back(val);
            conjunto.push_back(elementos);
        }
    }
    else {
        // El conjunto contiene más de un elemento, por lo que lo procesamos normalmente
        for (std::sregex_iterator i = begin; i != end; ++i) {
            std::smatch match = *i;
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
    }
    return conjunto;
}

conjuntoType Conjunto::getConjunto() { return conjunto; }

std::vector<tiposRelacion> Conjunto::clasificarR(Conjunto& R) {
    std::vector<tiposRelacion> cumple;
    
    if (esReflexiva(R)) {
        es_reflexiva = true;
        cumple.push_back(REFLEXIVA);
    }
    if (esIrreflexiva(R)) cumple.push_back(IRREFLEXIVA);
    if (esSimetrica(R)) {
        es_simetrica = true;
        cumple.push_back(SIMETRICA);
    }
    if (es_simetrica && !es_reflexiva && esAsimetrica(R)) {
        es_asimetrica = true;
        cumple.push_back(ASIMETRICA);
    }
    if (!es_simetrica && !es_asimetrica && esAntisimetrica(R)) cumple.push_back(ANTISIMETRICA);
    if (esTransitiva(R)) cumple.push_back(TRANSITIVA);
    if (esEquivalente(R)) cumple.push_back(EQUIVALENCIA);
    if (esOrdenParcial(R)) cumple.push_back(ORDEN_PARCIAL);
    return cumple;
}

size_t Conjunto::size() { return conjunto.size(); }

bool Conjunto::include(elementoPair sub_conjunto) {
    for (auto elemento : conjunto) {
        if (elemento.size() < 1) continue;
        if (elemento[0] == sub_conjunto.first && elemento[1] == sub_conjunto.second) return true;
    }
    return false;
}

bool Conjunto::esReflexiva(Conjunto &R) {
    for (auto elemento : conjunto) {
        if (!R.include(std::make_pair(elemento[0], elemento[0]))) {
            return false;
        }
    }
    return true;
}
bool Conjunto::esIrreflexiva(Conjunto& R) {
    for (auto elemento : R) {
        if (elemento[0] == elemento[0]) return false;
    }
    return true;
}

bool Conjunto::esSimetrica(Conjunto &R) {
    for (auto sub_conjunto : R) {
        elementoPair inverso= std::make_pair(sub_conjunto[1], sub_conjunto[0]); //
        if (!R.include(inverso)) return false;
    }
    return true;
}

conjuntoType::iterator Conjunto::begin() { return conjunto.begin(); }
conjuntoType::iterator Conjunto::end() { return conjunto.end(); }

std::ostream& operator<<(std::ostream& os, const Conjunto& conjunto) {
    os << "{ ";
    for (const auto& conjunto : conjunto.conjunto) {
        os << "(";
        for (auto elemento = conjunto.begin(); elemento != conjunto.end(); ++elemento)
            os << *elemento << (elemento + 1 == conjunto.end() ? "" : ",");
        os << "), ";
    }
    os << "}";
    return os;
}

Conjunto::operator conjuntoType() const { return conjunto; }
bool Conjunto::esAntisimetrica(Conjunto &R) {// elemento
    for (auto elemento : R.conjunto) { // {{"1", "1"}, {"1","2"}, {"1","3"}}
        for (auto elemento2 : R.conjunto) {
            if (elemento[0] == elemento2[1] && elemento[1] == elemento2[0] && elemento[0] != elemento[1]) return false;
        }
    }
    return true;
}
bool Conjunto::esAsimetrica(Conjunto &R) {
    for (auto elemento : R.conjunto) {
        for (auto elemento2 : R.conjunto) {
            if (elemento[0] == elemento2[1] && elemento[1] == elemento2[0] && elemento[0] == elemento[1]) return false;
        }
    }
    return true;
}

bool Conjunto::esTransitiva(Conjunto& R) {
    for (auto it1 = R.begin(); it1 != R.end(); ++it1) {
        for (auto it2 = R.begin(); it2 != R.end(); ++it2) {
            // Si existe una relación entre it1 y it2
            if (it1->at(1) == it2->at(0)) {
                // Buscamos una relación entre it1 y cualquier otro elemento relacionado indirectamente con it2
                for (auto it3 = R.begin(); it3 != R.end(); ++it3) {
                    if (it2->at(1) == it3->at(0) && !R.include({ it1->at(0), it3->at(1) })) {
                        return false; // La relación no es transitiva
                    }
                }
            }
        }
    }
    return true; // La relación es transitiva
}

bool Conjunto::esEquivalente(Conjunto &R) {
    return esReflexiva(R) && esSimetrica(R) && esTransitiva(R);
}
bool Conjunto::esOrdenParcial(Conjunto& R) {
    return esReflexiva(R) && (!es_simetrica && !es_asimetrica && esAntisimetrica(R)) && esTransitiva(R);
}

Conjunto Conjunto::conjuntoCociente(Conjunto& R) {
    std::set<std::set<string>> conjunto_cociente;
    for (auto inicio : conjunto)
    {
        std::set<string> clase_equivalencia;
        for (auto relacion: R)
        {
            if (relacion[0]==inicio[1])//quiero el a == conjunto en i
            {
                clase_equivalencia.insert(relacion[1]);//para el segundo
            }
            if (relacion[1]==inicio[1])//quiero el b ==conjunto en i
            {
                clase_equivalencia.insert(relacion[0]);//para el primero
            }
        }
        conjunto_cociente.insert(clase_equivalencia);//la clase equivalencia se agrega al conjunto cociente
    }
    cout << "conjunto cociente: { ";
    for (auto it=conjunto_cociente.begin();it!=conjunto_cociente.end();it++)
    {
        cout << "{ ";
        for (auto t2=it->begin();t2 !=it->end();t2++)
        {
            cout << *t2;//imprime el elemento apuntado por t2
            if (next(t2)!=it->end())
            {
                cout << ",";
            }
        }cout << " }";
        if (next(it)!=conjunto_cociente.end())
        {
            cout << ", ";
        }
    }
    cout << "} ";
}

void Conjunto::push_back(std::string elemento) {
    elemento.erase(std::remove_if(elemento.begin(), elemento.end(), [](char c) {
        return c == '(' || c == ')';
        }), elemento.end());
    if (elemento.length() == 1) conjunto.push_back({ elemento });

    std::stringstream ss(elemento);
    std::string element;
   std:: vector<std::string> elementos;
    while (std::getline(ss, element, ',')) {
        elementos.push_back(element);
    }
    conjunto.push_back(elementos);
}

#endif // CONJUNTO_H
