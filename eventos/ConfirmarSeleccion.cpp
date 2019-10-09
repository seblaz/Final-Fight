//
// Created by sebas on 8/10/19.
//

#include "ConfirmarSeleccion.h"
#include "../servidor/NivelServidor.h"

ConfirmarSeleccion::ConfirmarSeleccion(Mapa *mapa) : mapa(mapa) {}

void ConfirmarSeleccion::resolver() {
    mapa->vaciarMapa();
    NivelServidor::generarJugador(mapa);
    NivelServidor::generarNivel("nivel1", mapa);
}
