//
// Created by sebas on 14/10/19.
//

#include "Actividad.h"

void Actividad::serializar(ostream &stream) {
    serializarEntero(stream, activo);
}

void Actividad::deserializar(istream &stream) {
    activo = deserializarEntero(stream);
}

Actividad::Actividad(bool activo) :
        activo(activo) {}
