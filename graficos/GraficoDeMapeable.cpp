//
// Created by felipe on 14/9/19.
//


#include "GraficoDeMapeable.h"

#include <utility>
#include "../servicios/Configuracion.h"
#include "../servicios/Locator.h"

GraficoDeMapeable::GraficoDeMapeable(FisicaDeMapeable *fisica, SDL_Texture *sprite, Animacion animacion) :
        fisica(fisica),
        sprite(sprite),
        animacion(std::move(animacion)) {}

void GraficoDeMapeable::actualizar(SDL_Renderer *renderer) {
    SDL_Rect posicionEnSprite = animacion.actualizarYDevolverPosicion();
    SDL_Rect posicionEnPantalla = calcularPosicionEnPantalla(fisica->posicion(), posicionEnSprite, animacion.escala());
    SDL_RenderCopy(renderer, sprite, &posicionEnSprite, &posicionEnPantalla);
}