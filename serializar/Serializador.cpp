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

void Serializador::serializarString(ostream &in, string string) {
    in << string << endl;
}

string Serializador::deserializarString(istream &stream) {
    string line;
    getline(stream, line);
    return line;
}

void Serializador::serializarBoolean(ostream &in, bool boolean) {
    in << boolean << endl;
}

bool Serializador::deserializarBoolean(istream &stream) {
    string line;
    getline(stream, line);
    return stoi(line);
}

