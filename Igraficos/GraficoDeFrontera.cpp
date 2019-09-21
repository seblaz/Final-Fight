//
// Created by sebas on 18/9/19.
//

#include "GraficoDeFrontera.h"

int GraficoDeFrontera::profundidad() {
    return -1;
}

void GraficoDeFrontera::actualizar(SDL_Renderer *renderer) {
    int alto = Locator::configuracion()->getIntValue("/resolucion/alto");
    int ancho = Locator::configuracion()->getIntValue("/resolucion/ancho");

    SDL_Rect fillRect = {0, 0, ancho, alto};
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
    SDL_RenderFillRect(renderer, &fillRect);
}
