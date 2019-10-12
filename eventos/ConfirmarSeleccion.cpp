//
// Created by sebas on 8/10/19.
//

#include "ConfirmarSeleccion.h"
#include "../servidor/NivelServidor.h"

ConfirmarSeleccion::ConfirmarSeleccion(Mapa *mapa, enum PERSONAJE personaje) :
mapa(mapa),personajeSeleccionado(personaje) {}

void ConfirmarSeleccion::resolver() {
    mapa->vaciarMapa();
    NivelServidor::generarJugador(mapa,personajeSeleccionado);
    NivelServidor::generarNivel("nivel1", mapa);
}
