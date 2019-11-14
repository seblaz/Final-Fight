//
// Created by franco on 13/11/19.
//

#include "Eliminado.h"

void Eliminado::eliminar() {
    this->eliminado = true;
}

bool Eliminado::status() {
    return this->eliminado;
}

void Eliminado::serializar(ostream &stream) {
    Serializable::serializarBoolean(stream, this->eliminado);
}

void Eliminado::deserializar(istream &stream) {
    this -> eliminado = Serializable::deserializarBoolean(stream);
}
