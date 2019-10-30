//
// Created by sebas on 30/8/19.
//

#include "Posicion.h"

Posicion::Posicion(int x, int y, int z): x(x), y(y), z(z) {}

void Posicion::mover(Velocidad& velocidad) {
    x = x + int(velocidad.x);
    y = y + int(velocidad.y);
    z = z + int(velocidad.z);
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

Posicion Posicion::operator-(const Posicion& otraPosicion) {
    return Posicion(x - otraPosicion.x, y - otraPosicion.y, z - otraPosicion.z);
}

void Posicion::setX(int xNuevo) {
    x = xNuevo;
}

void Posicion::serializar(ostream &stream) {
    serializarEntero(stream, x);
    serializarEntero(stream, y);
    serializarEntero(stream, z);
}

void Posicion::deserializar(istream &stream) {
    x = deserializarEntero(stream);
    y = deserializarEntero(stream);
    z = deserializarEntero(stream);
}

bool Posicion::operator==(const Posicion &otraPosicion) {
    return (x == otraPosicion.x) && (y == otraPosicion.y) && (z == otraPosicion.z);
}


