//
// Created by franco on 20/10/19.
//

#include <numeric>
#include <utility>
#include "AnimacionServidor.h"
#include "../modelo/IndiceSprite.h"

AnimacionServidor::AnimacionServidor(vector<int> duracionesPorSprite, int duracionTotal) {
    this->duracionesPorSprite = std::move(duracionesPorSprite);
    this->duracionTotal = duracionTotal;
    this->spriteActual = 0;
    this->sumaDeDuracionesRelativas = accumulate(this->duracionesPorSprite.begin(), this->duracionesPorSprite.end(), 0.0f);
    this->framesFaltantes = calcularFramesFaltantes();
}

int AnimacionServidor::calcularFramesFaltantes() {
    float velocidad = Locator::configuracion()->getFloatValue("/velocidad/juego");
    return int(float(duracionTotal) * duracionesPorSprite[spriteActual] / sumaDeDuracionesRelativas * (1 / velocidad));
}

void AnimacionServidor::actualizar(Entidad* entidad) {
    framesFaltantes--;
    if (framesFaltantes <= 0) {
        spriteActual = (int)((spriteActual + 1) % duracionesPorSprite.size());
        framesFaltantes = calcularFramesFaltantes();
    }
    entidad->getEstado<IndiceSprite>("indice sprite")->setIndice(spriteActual);
}

