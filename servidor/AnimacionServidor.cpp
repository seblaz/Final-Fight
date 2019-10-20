//
// Created by franco on 20/10/19.
//

#include <numeric>
#include "AnimacionServidor.h"
#include "../modelo/PosicionSprite.h"

AnimacionServidor::AnimacionServidor(vector<float> duracionesPorSprite, int duracionTotal, int cantidadDeSprites) {
    this->duracionesPorSprite = duracionesPorSprite;
    this->duracionTotal = duracionTotal;
    this->spriteActual = 0;
    this->sumaDeDuracionesRelativas = accumulate(this->duracionesPorSprite.begin(), this->duracionesPorSprite.end(), 0.0f);
    this->framesFaltantes = calcularFramesFaltantes();
    this->cantidadDeSprites = cantidadDeSprites;
}

int AnimacionServidor::calcularFramesFaltantes() {
    float velocidad = Locator::configuracion()->getFloatValue("/velocidad/juego");
    return duracionTotal * duracionesPorSprite[spriteActual] / sumaDeDuracionesRelativas * (1 / velocidad);
}

void AnimacionServidor::actualizar(Entidad* entidad) {
    framesFaltantes--;
    if (framesFaltantes <= 0) {
        spriteActual = (spriteActual + 1) % cantidadDeSprites;
        framesFaltantes = calcularFramesFaltantes();
    }
    entidad->getEstado<PosicionSprite>("posicion sprite")->setPosicion(spriteActual);
    //return posiciones[spriteActual];
}

