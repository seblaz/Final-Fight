//
// Created by franco on 17/10/19.
//

#include "Jugadores.h"

#include <utility>
#include "serializables/Posicion.h"
#include "serializables/Actividad.h"
#include "serializables/Energia.h"
#include "serializables/EstadoDePersonaje.h"
#include "../servicios/Locator.h"

Jugadores::Jugadores(unordered_map<IdEntidad, Entidad *> jugadores) {
    Jugadores::jugadores = std::move(jugadores);
}

void Jugadores::agregarJugador(IdEntidad id, Entidad *jugador) {
    jugadores[id] = jugador;
}

unordered_map<IdEntidad, Entidad *> &Jugadores::getJugadores() {
    return jugadores;
}

int Jugadores::getMayorX() {
    int x = 0;
    for(auto tuple : jugadores){
        if ( tuple.second->getEstado<Posicion>("posicion")->getX() > x &&
             tuple.second->getEstado<Actividad>("actividad")->activo &&
                tuple.second->getEstado<Energia>("energia")->vivo())
            x = tuple.second->getEstado<Posicion>("posicion")->getX();
    }
    return x;
}

int Jugadores::getMenorX() {
    int x = 99999999;
    for(auto tuple : jugadores){
        if ( tuple.second->getEstado<Posicion>("posicion")->getX() < x &&
             tuple.second->getEstado<Actividad>("actividad")->activo &&
             tuple.second->getEstado<Energia>("energia")->vivo())
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

void Jugadores::bloquearMovimientos(int scrollIzquierdo, int scrollDerecho) {
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
        if (!tuple.second->getEstado<Actividad>("actividad")->activo ||
             !tuple.second->getEstado<Energia>("energia")->vivo()){
            int x = tuple.second->getEstado<Posicion>("posicion")->getX();
            if ( x >= scrollDerecho ){
                tuple.second->getEstado<Posicion>("posicion")->x = scrollDerecho;
            }else if ( x <= scrollIzquierdo ){
                tuple.second->getEstado<Posicion>("posicion")->x = scrollIzquierdo;
            }
        }
    }
}

Posicion Jugadores::posicionMasCercana(Posicion *posicion) {
    Posicion posicionMasCercana(3000, 1000, 100);

    for(auto tuple: jugadores){
        if (tuple.second->getEstado<Actividad>("actividad")->activo &&
                tuple.second->getEstado<Energia>("energia")->vivo()){
            auto* posicionJugador = tuple.second->getEstado<Posicion>("posicion");
            int distJugadorYenemigo = posicionJugador->distanciaEntrePuntos(posicion);
            int distMasCercanaActual = posicionMasCercana.distanciaEntrePuntos(posicion);
            if ( distJugadorYenemigo < distMasCercanaActual){
                posicionMasCercana.x = posicionJugador->x;
                posicionMasCercana.y = posicionJugador->y;
                posicionMasCercana.z = posicionJugador->z;
            }
        }
    }
    return posicionMasCercana;
}

bool Jugadores::vivos() {
    if(jugadores.empty()) return true;
    for(auto tuple: jugadores) {
        if(tuple.second->getEstado<Actividad>("actividad")->activo &&
                tuple.second->getEstado<Energia>("energia")->vivo())
            return true;
    }
    return false;
}
