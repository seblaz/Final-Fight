//
// Created by sebas on 9/10/19.
//

#include "EventoPersonaje.h"
#include "../estados/EstadoDePersonaje.h"

Reposar::Reposar(Mapa *mapa) : mapa(mapa) {}

void Reposar::resolver() {
    Entidad *entidad = mapa->getJugador();
    entidad->getEstado<EstadoDePersonaje>("estado")->reposar(entidad);
}

Saltar::Saltar(Mapa *mapa) : mapa(mapa) {}

void Saltar::resolver() {
    Entidad *entidad = mapa->getJugador();
    entidad->getEstado<EstadoDePersonaje>("estado")->saltar(entidad);
}

Golpear::Golpear(Mapa *mapa) : mapa(mapa) {}

void Golpear::resolver() {
    Entidad *entidad = mapa->getJugador();
    entidad->getEstado<EstadoDePersonaje>("estado")->golpear(entidad);
}
