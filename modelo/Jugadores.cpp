//
// Created by franco on 17/10/19.
//

#include "Jugadores.h"

#include <utility>
#include "Posicion.h"

Jugadores::Jugadores(unordered_map<IdEntidad, Entidad *> jugadores) {
    Jugadores::jugadores = std::move(jugadores);
    for(auto tuple : jugadores){
        posiciones[tuple.first] = tuple.second->getEstado<Posicion>("posicion");
    }
}

int Jugadores::getMayorX() {
    int x = 0;
    for(auto tuple : jugadores){
        if ( tuple.second->getEstado<Posicion>("posicion")->getX() > x )
            x = tuple.second->getEstado<Posicion>("posicion")->getX();
    }
    return x;
}

int Jugadores::getMenorX() {
    int x = 99999999;
    for(auto tuple : jugadores){
        if ( tuple.second->getEstado<Posicion>("posicion")->getX() < x )
            x = tuple.second->getEstado<Posicion>("posicion")->getX();
    }
    return x;
}

void Jugadores::reiniciarPosiciones(int x, int y) {
    for(auto tuple : jugadores){
        tuple.second->getEstado<Posicion>("posicion")->x = x;
        tuple.second->getEstado<Posicion>("posicion")->y = y;
    }
}

unordered_map<IdEntidad, Posicion *>* Jugadores::getPosiciones() {
    return &posiciones;
}





