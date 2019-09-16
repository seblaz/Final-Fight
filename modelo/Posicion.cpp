//
// Created by sebas on 30/8/19.
//

#include "Posicion.h"

Posicion::Posicion(int x, int y, int z): x(x), y(y), z(z) {}

void Posicion::mover(Velocidad& velocidad) {
    x += int(velocidad.x);
    y += int(velocidad.y);
    z += int(velocidad.z);
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

Posicion Posicion::operator-(Posicion otraPosicion) {
    return Posicion(x - otraPosicion.x, y - otraPosicion.y, z - otraPosicion.z);
}


