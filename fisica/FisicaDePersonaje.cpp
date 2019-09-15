//
// Created by sebas on 2/9/19.
//

#include "FisicaDePersonaje.h"

FisicaDePersonaje::FisicaDePersonaje(int x, int y, int z) :
        posicion_(x, y, z) {}

void FisicaDePersonaje::actualizar() {
    posicion_.mover(velocidad_);
}

Posicion FisicaDePersonaje::posicion() {
    return posicion_;
}

Velocidad FisicaDePersonaje::velocidad() {
    return velocidad_;
}

void FisicaDePersonaje::cambiarVelocidadX(float x) {
    velocidad_.x = x;
}

void FisicaDePersonaje::cambiarVelocidadY(float y) {
    velocidad_.y = y;
}

void FisicaDePersonaje::cambiarVelocidadZ(float z) {
    velocidad_.z = z;
}