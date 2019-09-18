//
// Created by sebas on 13/9/19.
//

#include "Animacion.h"
#include "../servicios/Locator.h"

#include <utility>
#include <stdexcept>
#include <numeric>

Animacion::Animacion(vector<SDL_Rect> posiciones, vector<float> duracionesPorSprite, int duracionTotal, float escala) :
        duracionesPorSprite(std::move(duracionesPorSprite)),
        posiciones(std::move(posiciones)),
        duracionTotal(duracionTotal),
        spriteActual(0),
        sumaDeDuracionesRelativas(
                accumulate(this->duracionesPorSprite.begin(), this->duracionesPorSprite.end(), 0.0f)),
        escala_(escala) {

    if (posiciones.size() != duracionesPorSprite.size())
        throw invalid_argument("Posiciones y duracionesPorSprite deben tener el mismo tamaño.");

    framesFaltantes = calcularFramesFaltantes();
}

SDL_Rect Animacion::actualizarYDevolverPosicion() {
    framesFaltantes--;
    if (framesFaltantes <= 0) {
        spriteActual = (spriteActual + 1) % posiciones.size();
        framesFaltantes = calcularFramesFaltantes();
    }
    return posiciones[spriteActual];
}

int Animacion::calcularFramesFaltantes() {
    float velocidad = Locator::configuracion()->getFloatValue("/velocidadDeJuego");
    return duracionTotal * duracionesPorSprite[spriteActual] / sumaDeDuracionesRelativas * (1 / velocidad);;
}

float Animacion::escala() {
    return escala_;
}

bool Animacion::compareTo(Animacion *animacionAcomparar) {

}