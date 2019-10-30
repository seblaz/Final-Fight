//
// Created by sebas on 20/10/19.
//

#include "EstadoDePersonaje.h"

EstadoDePersonaje::EstadoDePersonaje() : estado(REPOSANDO) {}

EstadoDePersonaje::EstadoDePersonaje(ESTADO_DE_PERSONAJE estado) : estado(estado) {}

ESTADO_DE_PERSONAJE EstadoDePersonaje::getEstado() {
    return estado;
}

void EstadoDePersonaje::serializar(ostream &stream) {
    serializarEntero(stream, estado);
}

void EstadoDePersonaje::deserializar(istream &stream) {
    estado = static_cast<enum ESTADO_DE_PERSONAJE>(deserializarEntero(stream));
}
