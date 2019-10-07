//
// Created by sebas on 6/10/19.
//

#include <iostream>
#include "Serializador.h"

void Serializador::serializarEntero(ostream &in, int entero) {
    in << entero << endl;
}

int Serializador::deserializarEntero(istream &stream) {
    string line;
    getline(stream, line);
    return stoi(line);
}
