//
// Created by sebas on 2/9/19.
//

#include "FisicaDePersonaje.h"

FisicaDePersonaje::FisicaDePersonaje(int x, int y, int z) :
        posicion_(x, y, z) {}

Posicion &FisicaDePersonaje::posicion() {
    return posicion_;
}

void FisicaDePersonaje::actualizar() {
    posicion_.mover(velocidad_);
}

Velocidad &FisicaDePersonaje::velocidad() {
    return velocidad_;
}


