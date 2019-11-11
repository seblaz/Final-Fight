//
// Created by franco on 31/10/19.
//

#include "EnvolventeVolumen.h"

bool EnvolventeVolumen::colisionaPorIzquierdaCon(EnvolventeVolumen *envolvente) {

    int x = this->posicion->getX();
    int y = posicion->y;
    int deltaY = this->posicion->y - envolvente->posicion->y;

    return (posicion->x + ancho > envolvente->posicion->x - envolvente->ancho &&
            posicion->x + ancho < envolvente->posicion->x &&
            y < envolvente->posicion->y + envolvente->profundidad &&
            y > envolvente->posicion->y - envolvente->profundidad);
}

bool EnvolventeVolumen::colisionaPorDerechaCon(EnvolventeVolumen *envolvente) {

    int x = posicion->x;
    int y = posicion->y;
    int deltaY = this->posicion->y - envolvente->posicion->y;
    return (posicion->x - ancho < envolvente->posicion->x + envolvente->ancho &&
            posicion->x - ancho > envolvente->posicion->x &&
            y < envolvente->posicion->y + envolvente->profundidad &&
            y > envolvente->posicion->y - envolvente->profundidad);
}

bool EnvolventeVolumen::colisionaAbajoCon(EnvolventeVolumen *envolvente) {

    int x = this->posicion->getX();

    return (x - ancho < envolvente->posicion->x + envolvente->ancho &&
            x + ancho > envolvente->posicion->x - envolvente->ancho &&
            envolvente->posicion->y + envolvente->profundidad > posicion->y - profundidad &&
            envolvente->posicion->y + envolvente->profundidad < posicion->y);
}

bool EnvolventeVolumen::colisionaArribaCon(EnvolventeVolumen *envolvente) {
    int x = this->posicion->getX();

    return (x - ancho < envolvente->posicion->x + envolvente->ancho &&
            x + ancho > envolvente->posicion->x - envolvente->ancho &&
            envolvente->posicion->y - envolvente->profundidad < posicion->y + profundidad &&
            envolvente->posicion->y - envolvente->profundidad > posicion->y);
}
