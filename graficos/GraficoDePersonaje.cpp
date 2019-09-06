//
// Created by sebas on 2/9/19.
//

#include "GraficoDePersonaje.h"
#include "../modelo/mapeables/Personaje.h"

void GraficosDePersonaje::actualizar(SDL_Renderer *renderer, Mapeable &mapeable) {
    Personaje & personaje = dynamic_cast<Personaje &>(mapeable);
    const int SCREEN_WIDTH = 1280;
    const int SCREEN_HEIGHT = 960;

    SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
    SDL_RenderClear(renderer);

    Posicion posicion = personaje.posicion();
    SDL_Rect fillRect = { posicion.getX(), posicion.getY(), SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };
    SDL_SetRenderDrawColor( renderer, 0xFF, 0x00, 0x00, 0xFF );
    SDL_RenderFillRect( renderer, &fillRect );
}
