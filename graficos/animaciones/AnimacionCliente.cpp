//
// Created by sebas on 13/9/19.
//

#include "AnimacionCliente.h"
#include "../../modelo/IndiceSprite.h"

#include <utility>

AnimacionCliente::AnimacionCliente(vector<SDL_Rect> posiciones, float escala) :
        posiciones(std::move(posiciones)),
        escala_(escala) {
}

SDL_Rect AnimacionCliente::devolverPosicion(Entidad *entidad) {

    int spriteActual = entidad->getEstado<IndiceSprite>("posicion sprite")->getIndice();
    return posiciones[spriteActual];
}

float AnimacionCliente::escala() {
    return escala_;
}
