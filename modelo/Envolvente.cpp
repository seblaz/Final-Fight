//
// Created by franco on 31/10/19.
//

#include "Envolvente.h"

Envolvente::Envolvente(Posicion *posicion, int alto, int ancho, int profundidad) {
    this->posicion = posicion;
    this->alto = alto;
    this->ancho = ancho;
    this->profundidad = profundidad;
}

bool Envolvente::existeColisionLeft(Envolvente *envolvente) {

    int x = this->posicion->getX();
    int y = posicion->y;
    int deltaY = this->posicion->y - envolvente->posicion->y;

    return (posicion->x + ancho > envolvente->posicion->x - envolvente->ancho &&
            posicion->x + ancho < envolvente->posicion->x &&
            y < envolvente->posicion->y + envolvente->profundidad && y > envolvente->posicion->y - envolvente->profundidad);
}

bool Envolvente::existeColisionRight(Envolvente *envolvente) {

    int x = posicion->x;
    int y = posicion->y;
    int deltaY = this->posicion->y - envolvente->posicion->y;
    return (posicion->x - ancho < envolvente->posicion->x + envolvente->ancho  &&
            posicion->x - ancho > envolvente->posicion->x &&
            y < envolvente->posicion->y + envolvente->profundidad && y > envolvente->posicion->y - envolvente->profundidad);
}

bool Envolvente::existeColisionUp(Envolvente *envolvente) {

    int x = this->posicion->getX();

    return( x < envolvente->posicion->x + envolvente->ancho && x > envolvente->posicion->x - envolvente->ancho  &&
    envolvente->posicion->y + envolvente->profundidad > posicion->y - profundidad &&
    envolvente->posicion->y + envolvente->profundidad < posicion->y);
}

bool Envolvente::existeColisionDown(Envolvente *envolvente) {
    int x = this->posicion->getX();

    return( x < envolvente->posicion->x + envolvente->ancho && x > envolvente->posicion->x - envolvente->ancho &&
    envolvente->posicion->y - envolvente->profundidad < posicion->y + profundidad &&
    envolvente->posicion->y - envolvente->profundidad > posicion->y);
}

