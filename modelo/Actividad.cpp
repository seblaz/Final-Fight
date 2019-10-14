//
// Created by sebas on 14/10/19.
//

#include "Actividad.h"

bool Actividad::estaActivo() {
    return activo_;
}

void Actividad::serializar(ostream &stream) {
    serializarEntero(stream, activo_);
}

void Actividad::deserializar(istream &stream) {
    activo_ = deserializarEntero(stream);
}

Actividad::Actividad(bool activo) :
        activo_(activo) {}
