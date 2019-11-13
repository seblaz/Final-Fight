//
// Created by sebas on 11/11/19.
//

#include "EnvolventeAtaque.h"

EnvolventeAtaque::EnvolventeAtaque(Posicion *posicion, int alto, int ancho, int profundidad, Orientacion *orientacion) :
        orientacion(orientacion),
        Envolvente(posicion, alto, ancho, profundidad) {}

bool EnvolventeAtaque::colisionaCon(EnvolventeVolumen *envolvente) {
    int mod = orientacion->adelante ? 1 : -1;
    return abs(posicion->x + ((ancho * mod) / 2) - envolvente->posicion->x) < ((ancho / 2) + envolvente->ancho) &&
           abs(posicion->y - envolvente->posicion->y) < (profundidad + envolvente->profundidad);

}

