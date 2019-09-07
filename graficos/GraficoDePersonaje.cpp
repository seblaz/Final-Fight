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
    SDL_Rect posicionJugador = {posicion.getX(), posicion.getY(), 200, 400 };

    //The final texture
    SDL_Texture* newTexture = NULL;

    //Load image at specified path
    SDL_Texture* image = IMG_LoadTexture( renderer, "assets/personajes/coddy.png" );

    SDL_Rect posicionTextura = { 5, 0, 40, 100 };

    SDL_RenderCopy(renderer, image, &posicionTextura, &posicionJugador);
    SDL_RenderPresent(renderer);
}
