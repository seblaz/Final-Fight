//
// Created by sebas on 5/11/19.
//

#include "ModeloJuego.h"

ModeloJuego::ModeloJuego(Mapa *mapa) :
        mapa(mapa) {}

void ModeloJuego::serializar(ostream &stream) {
    Modelo::serializar(stream);
    // TODO.
}

void ModeloJuego::deserializar(istream &stream) {
    Modelo::deserializar(stream);
    // TODO.
}
