//
// Created by sebas on 30/8/19.
//

#include <cstdio>
#include "Posicion.h"

Posicion::Posicion(int x, int y, int z): x(x), y(y), z(z) {}

void Posicion::mover(Velocidad& velocidad) {
    x += velocidad.x;
    y += velocidad.y;
    z += velocidad.z;
}

int Posicion::getX() {
    return x;
}

int Posicion::getY() {
    return y;
}

int Posicion::getZ() {
    return z;
}


