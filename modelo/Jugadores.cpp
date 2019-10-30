//
// Created by franco on 17/10/19.
//

#include "Jugadores.h"

#include <utility>
#include "serializables/Posicion.h"
#include "serializables/Actividad.h"

Jugadores::Jugadores(unordered_map<IdEntidad, Entidad *> jugadores) {
    Jugadores::jugadores = std::move(jugadores);
}

int Jugadores::getMayorX() {
    int x = 0;
    for(auto tuple : jugadores){
        if ( tuple.second->getEstado<Posicion>("posicion")->getX() > x && tuple.second->getEstado<Actividad>("actividad")->activo)
            x = tuple.second->getEstado<Posicion>("posicion")->getX();
    }
    return x;
}

int Jugadores::getMenorX() {
    int x = 99999999;
    for(auto tuple : jugadores){
        if ( tuple.second->getEstado<Posicion>("posicion")->getX() < x && tuple.second->getEstado<Actividad>("actividad")->activo)
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

void Jugadores::bloquearMovientos(int scrollIzquierdo, int scrollDerecho) {
    for(auto tuple : jugadores){
        int x = tuple.second->getEstado<Posicion>("posicion")->getX();
        if ( x >= scrollDerecho ){
            tuple.second->getEstado<Posicion>("posicion")->x = scrollDerecho;
        }else if ( x <= scrollIzquierdo ){
            tuple.second->getEstado<Posicion>("posicion")->x = scrollIzquierdo;
        }
    }
}

void Jugadores::arrastrarInactivos(int scrollIzquierdo, int scrollDerecho) {
    for(auto tuple : jugadores){
        if (!tuple.second->getEstado<Actividad>("actividad")->activo){
            int x = tuple.second->getEstado<Posicion>("posicion")->getX();
            if ( x >= scrollDerecho ){
                tuple.second->getEstado<Posicion>("posicion")->x = scrollDerecho;
            }else if ( x <= scrollIzquierdo ){
                tuple.second->getEstado<Posicion>("posicion")->x = scrollIzquierdo;
            }
        }
    }
}





