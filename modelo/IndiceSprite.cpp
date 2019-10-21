//
// Created by franco on 20/10/19.
//

#include "IndiceSprite.h"

void IndiceSprite::serializar(ostream &stream) {
    Serializable::serializarEntero(stream, indice);
}

void IndiceSprite::deserializar(istream &stream) {
    this->indice = Serializable::deserializarEntero(stream);
}

void IndiceSprite::setIndice(int posicion) {
    this->indice = posicion;
}

int IndiceSprite::getIndice() {
    return this->indice;
}