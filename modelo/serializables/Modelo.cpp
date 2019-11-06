//
// Created by sebas on 5/11/19.
//

#include "Modelo.h"

#include <utility>

void Modelo::setId(IdEtapa id_) {
    id = std::move(id_);
}

IdEtapa Modelo::getId() {
    return id;
}

void Modelo::serializar(ostream &stream) {
    serializarString(stream, id);
}

void Modelo::deserializar(istream &stream) {
    id = deserializarString(stream);
}
