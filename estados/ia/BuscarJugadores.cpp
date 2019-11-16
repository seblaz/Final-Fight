//
// Created by franco on 29/10/19.
//

#include "BuscarJugadores.h"

BuscarJugadores::BuscarJugadores(Entidad *entidad, Jugadores *jugadores) :
        Comportamiento(entidad), jugadores(jugadores) {}

void BuscarJugadores::actualizar() {
    Locator::eventos()->push(new EventoBuscarJugadores(jugadores, entidad));
}

EventoBuscarJugadores::EventoBuscarJugadores(Jugadores *jugadores, Entidad *entidad) :
        entidad(entidad),
        jugadores(jugadores) {}

void EventoBuscarJugadores::resolver() {
    auto *estado = entidad->getComportamiento<EstadoDePersonajeServidor>("estado");
    auto *estadoDePersonaje = entidad->getEstado<EstadoDePersonaje>("estado de personaje");

    auto *posicion = entidad->getEstado<Posicion>("posicion");
    auto posicionMasCercana = jugadores->posicionMasCercana(posicion);

    Posicion restaPosicion = posicion->menos(&posicionMasCercana);
    float mod = restaPosicion.modulo();
    if ( mod <= 1000 ) {
        if( mod >= 100 ) {
            int num = 1 + rand() % (101 - 1);
            if( num > 85){
                estado->saltar();
            }else{
                estado->caminar(restaPosicion.x <= 0, restaPosicion.x > 0, restaPosicion.y < 0,
                                restaPosicion.y > 0);
            }
        }else{
            //TODO atacar
            int num = 1 + rand() % (101 - 1);
            if( num > 5 && restaPosicion.x > 10){
                estado->caminar(restaPosicion.x <= 0, restaPosicion.x > 0, restaPosicion.y < 0,
                                restaPosicion.y > 0);
            }else{
                //estado->darGolpe();
            }
        }
    }else{
        estado->reposar();
    }
}
