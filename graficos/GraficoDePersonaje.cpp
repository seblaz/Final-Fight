//
// Created by sebas on 13/9/19.
//

#include "GraficoDePersonaje.h"
#include <utility>

GraficoDePersonaje::GraficoDePersonaje(FisicaDePersonaje *fisica, SDL_Texture *sprite, Animacion animacion) :
        sprite(sprite),
        haciaAdelante(true),
        animacion(std::move(animacion)),
        fisica(fisica) {}


void GraficoDePersonaje::actualizar(SDL_Renderer *renderer) {
    SDL_Rect posicionEnSprite = animacion.actualizarYDevolverPosicion();
    SDL_Rect posicionEnPantalla = calcularPosicionEnPantalla(fisica->posicion(), posicionEnSprite, animacion.escala());

    Velocidad velocidad = fisica->velocidad();
    if(velocidad.x != 0){
       haciaAdelante = velocidad.x > 0;
    }
    if(haciaAdelante){
        SDL_RenderCopy(renderer, sprite, &posicionEnSprite, &posicionEnPantalla);
    } else {
        SDL_RenderCopyEx(renderer, sprite, &posicionEnSprite, &posicionEnPantalla, 180, nullptr, SDL_FLIP_VERTICAL);
    }
}

void GraficoDePersonaje::cambiarAnimacion(Animacion nuevaAnimacion) {
    this->animacion = std::move(nuevaAnimacion);
}
