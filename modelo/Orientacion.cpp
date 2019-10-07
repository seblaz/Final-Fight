//
// Created by sebas on 21/9/19.
//

#include "Orientacion.h"

void Orientacion::serializar(ostream &stream) {
    serializarBoolean(stream, adelante);
}

void Orientacion::deserializar(istream &stream) {
    adelante = deserializarBoolean(stream);
}

Orientacion::Orientacion(bool adelante) {
    this -> adelante = adelante;
}
