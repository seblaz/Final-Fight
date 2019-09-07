//
// Created by sebas on 2/9/19.
//

#include "GraficoDePersonaje.h"
#include "../modelo/mapeables/Personaje.h"

void GraficosDePersonaje::actualizar(SDL_Renderer *renderer, Mapeable &mapeable) {
    Personaje &personaje = dynamic_cast<Personaje &>(mapeable);

    //Se Construye el escenario
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(renderer);

    //Se obtiene la posicion del juegador y en base a eso se construye el hitbox del jugador
    Posicion posicion = personaje.posicion();
    SDL_Rect posicionJugador = {posicion.getX(), posicion.getY(), 200, 400};

    //Se carga la plantilla de sprites
    // Se debe cargar la primera vez!!! TODO

    SDL_Surface* spriteOriginal = IMG_Load("assets/personajes/coddy.png");
    SDL_SetColorKey( spriteOriginal, SDL_TRUE, SDL_MapRGB( spriteOriginal->format, 0X58, 0xB8, 0xF8 ) );
    SDL_Texture* spriteTransparente = SDL_CreateTextureFromSurface( renderer, spriteOriginal );

    //Se setea la posicion de la plantilla de sprites (La posicion y dimension que se va a renderizar LA PLANTILLA DE SPRITES, no el hitbox)
    SDL_Rect posicionSprite = { 5, 0, 40, 100 };

    //Se renderiza en la ventana la imagen, la posicion del sprite, y la posicion del jugador
    SDL_RenderCopy(renderer, spriteTransparente, &posicionSprite, &posicionJugador);
    SDL_RenderPresent(renderer);

}
