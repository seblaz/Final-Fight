//
// Created by sebas on 10/9/19.
//

#include "GraficoDeEscenario.h"
#include "../modelo/mapeables/Escenario.h"

GraficoDeEscenario::GraficoDeEscenario(SDL_Renderer *renderer, string rutaSprite) :
        renderer(renderer) {
    SDL_Surface *sprite = IMG_Load(rutaSprite.c_str());
    SDL_SetColorKey(sprite, SDL_TRUE, SDL_MapRGB(sprite->format, 0X58, 0xB8, 0xF8));
    texture = SDL_CreateTextureFromSurface(renderer, sprite);
    SDL_FreeSurface(sprite);
}

void GraficoDeEscenario::actualizar(Mapeable &mapeable) {
    auto &escenario = dynamic_cast<Escenario &>(mapeable);

//    Posicion &posicion = escenario.posicion(); // Se obtiene la posicion del jugador y en base a eso se construye el hitbox del jugador.
//    SDL_Rect posicionJugador = {posicion.getX(), posicion.getY(), 200, 400};
    //Se setea la posicion de la plantilla de sprites (La posicion y dimension que se va a renderizar LA PLANTILLA DE SPRITES, no el hitbox)
//    TODO: poner estas coordenadas para cada sprite aca es turbio, hace falta sacarlo de aca (idea: tener una clase sprite).
    SDL_Rect posicionSprite = {0, 0, 300, 195};
    SDL_Rect posicionEscenario = {0, 0, 1280, 960};

    //Se renderiza en la ventana la imagen, la posicion del sprite, y la posicion del jugador
    SDL_RenderCopy(renderer, texture, &posicionSprite, &posicionEscenario);
}
