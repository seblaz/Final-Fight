//
// Created by sebas on 13/9/19.
//

#include "GraficoDePersonaje.h"
#include <utility>

GraficoDePersonaje::GraficoDePersonaje(FisicaDePersonaje *fisica,
                                        FisicaDeEscenario &fisicaDeEscenario,
                                        SDL_Texture *sprite,
                                        Animacion *animacion,
                                        Comportamiento *comportamiento) :
        sprite(sprite),
        haciaAdelante(true),
        animacion(std::move(animacion)),
        fisica(fisica),
        comportamiento(comportamiento),
        fisicaDeEscenario(fisicaDeEscenario) {}


void GraficoDePersonaje::actualizar(SDL_Renderer *renderer) {
    Animacion* nuevaAnimacion = comportamiento->devolverAnimacion();
    if (nuevaAnimacion != animacion){
        cambiarAnimacion(nuevaAnimacion);
    }
    Posicion nuevaPosicion(fisica->posicion().getX() - fisicaDeEscenario.posicion(), fisica->posicion().getY(),
                           fisica->posicion().getZ());
    SDL_Rect posicionEnSprite = animacion->actualizarYDevolverPosicion();
    SDL_Rect posicionEnPantalla = calcularPosicionEnPantalla(nuevaPosicion, posicionEnSprite, animacion->escala());

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

void GraficoDePersonaje::cambiarAnimacion(Animacion *nuevaAnimacion) {
    delete animacion;
    this->animacion = nuevaAnimacion;
}

int GraficoDePersonaje::profundidad() {
    return fisica->posicion().getY();
}
