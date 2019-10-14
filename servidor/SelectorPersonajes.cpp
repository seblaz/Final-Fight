//
// Created by sebas on 13/10/19.
//

#include "SelectorPersonajes.h"

SelectorPersonajes::SelectorPersonajes(int jugadores) :
        jugadores(jugadores){}

void SelectorPersonajes::confirmar() {
    jugadores -= 1;
}

bool SelectorPersonajes::puedoComenzar() {
    return jugadores == 0;
}
