//
// Created by sebas on 9/10/19.
//

#include "Nivel.h"

#include <utility>

Nivel::Nivel() : nivel_("nivel1") {}

Nivel::Nivel(string nivel) : nivel_(std::move(nivel)){}

string Nivel::nivel() {
    return nivel_;
}

void Nivel::serializar(ostream &stream) {
    serializarString(stream, nivel_);
}

void Nivel::deserializar(istream &stream) {
    nivel_ = deserializarString(stream);
}
