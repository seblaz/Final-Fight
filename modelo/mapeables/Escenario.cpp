//
// Created by sebas on 10/9/19.
//

#include "Escenario.h"

Escenario::Escenario(int x, int y, int z, Mapa *mapa, Fisica *fisica, Grafico *grafico) :
        Mapeable(x, y, z, mapa, fisica, grafico) {}

void Escenario::actualizar(SDL_Renderer *renderer) {
    Mapeable::actualizar(renderer);
}
