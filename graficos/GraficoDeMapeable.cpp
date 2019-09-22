//
// Created by felipe on 14/9/19.
//


#include "GraficoDeMapeable.h"

#include <utility>
#include "../fisica/FisicaDeEscenario.h"

GraficoDeMapeable::GraficoDeMapeable(FisicaDeMapeable *fisica, FisicaDeEscenario &fisicaDeEscenario,
                                     SDL_Texture *sprite, Animacion* animacion) :
        fisica(fisica),
        sprite(sprite),
        animacion(std::move(animacion)),
        fisicaDeEscenario(fisicaDeEscenario) {}

void GraficoDeMapeable::actualizar(SDL_Renderer *renderer) {
    Posicion nuevaPosicion(fisica->posicion().getX() - fisicaDeEscenario.posicion(), fisica->posicion().getY(),
                           fisica->posicion().getZ());
    SDL_Rect posicionEnSprite = animacion->actualizarYDevolverPosicion();
    SDL_Rect posicionEnPantalla = calcularPosicionEnPantalla(nuevaPosicion, posicionEnSprite, animacion->escala());
    SDL_RenderCopy(renderer, sprite, &posicionEnSprite, &posicionEnPantalla);
}

int GraficoDeMapeable::profundidad() {
    return fisica->posicion().getY();
}
