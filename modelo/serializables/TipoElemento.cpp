//
// Created by franco on 13/10/19.
//

#include "TipoElemento.h"

void TipoElemento::serializar(ostream &stream) {
    serializarEntero(stream, elemento);
}

void TipoElemento::deserializar(istream &stream) {
    elemento = deserializarEntero(stream);
}

int TipoElemento::getElemento() {
    return this->elemento;
}

TipoElemento::TipoElemento(int art) {
    this -> elemento = art;
}