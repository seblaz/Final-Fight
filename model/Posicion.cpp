//
// Created by sebas on 30/8/19.
//

#include "Posicion.h"

Posicion::Posicion(int x, int y, int z): x(x), y(y), z(z) {}

void Posicion::mover(Direccion& direccion) {
    x += direccion.x;
    y += direccion.y;
    z += direccion.z;
}


