//
// Created by sebas on 13/9/19.
//

#include "AnimacionCliente.h"
#include "../../modelo/serializables/IndiceSprite.h"

#include <utility>

AnimacionCliente::AnimacionCliente(vector<SDL_Rect> posiciones, float escala) :
        posiciones(std::move(posiciones)),
        escala_(escala) {
}

SDL_Rect AnimacionCliente::devolverPosicion(Entidad *entidad) {
    auto *indiceSprite = entidad->getEstado<IndiceSprite>("indice sprite");
    int spriteActual = indiceSprite->getIndice();
    return posiciones[spriteActual];
}

float AnimacionCliente::escala() {
    return escala_;
}
