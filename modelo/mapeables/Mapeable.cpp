//
// Created by sebas on 30/8/19.
//

#include <SDL_system.h>
#include "Mapeable.h"

Mapeable::Mapeable(int x, int y, int z, Mapa *mapa, Fisica *fisica, Grafico *grafico) :
        _posicion(x, y, z),
        grafico(grafico),
        physics(fisica),
        mapa(mapa) {}

void Mapeable::actualizar(SDL_Renderer *renderer) {
    physics->actualizar(*mapa, *this);
    grafico->actualizar(*this);
}

Posicion &Mapeable::posicion() {
    return _posicion;
}
