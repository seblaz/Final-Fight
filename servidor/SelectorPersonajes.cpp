//
// Created by sebas on 13/10/19.
//

#include "SelectorPersonajes.h"

SelectorPersonajes::SelectorPersonajes(int jugadores) :
        jugadores(jugadores){}

void SelectorPersonajes::confirmar() {
    unique_lock<mutex> lock(m_mutex);
    jugadores -= 1;
}

bool SelectorPersonajes::puedoComenzar() {
    unique_lock<mutex> lock(m_mutex);
    return jugadores == 0;
}
