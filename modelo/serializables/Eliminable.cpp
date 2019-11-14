//
// Created by franco on 13/11/19.
//

#include "Eliminable.h"

void Eliminable::eliminar() {
    this->eliminado = true;
}

bool Eliminable::status() {
    return this->eliminado;
}

void Eliminable::serializar(ostream &stream) {
    Serializable::serializarBoolean(stream, this->eliminado);
}

void Eliminable::deserializar(istream &stream) {
    this -> eliminado = Serializable::deserializarBoolean(stream);
}
