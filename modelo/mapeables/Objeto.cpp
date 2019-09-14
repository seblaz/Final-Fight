//
// Created by felipe on 14/9/19.
//


#include "../Mapa.h"
#include "Objeto.h"

Objeto::Objeto(int x, int y, int z, Mapa *mapa, Fisica *fisica, Grafico *grafico) :
        Mapeable(x, y, z, mapa, fisica, grafico) {}

void Objeto::actualizar(SDL_Renderer *renderer) {
    Mapeable::actualizar(renderer);
}
