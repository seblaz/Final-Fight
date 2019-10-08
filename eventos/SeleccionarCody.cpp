//
// Created by sebas on 8/10/19.
//

#include "SeleccionarCody.h"
#include "../servidor/NivelServidor.h"

SeleccionarCody::SeleccionarCody(Mapa *mapa) : mapa(mapa) {}

void SeleccionarCody::resolver() {
    mapa->vaciarMapa();
    NivelServidor::generarJugador(mapa);
}
