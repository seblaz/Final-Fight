//
// Created by franco on 29/10/19.
//

#include "BuscarJugadores.h"

BuscarJugadores::BuscarJugadores(Jugadores *jugadores) :
        jugadores(jugadores) {}

void BuscarJugadores::actualizar(Entidad *entidad) {
    Locator::eventos()->push(new EventoBuscarJugadores(jugadores, entidad));
}

EventoBuscarJugadores::EventoBuscarJugadores(Jugadores *jugadores, Entidad *entidad) :
        entidad(entidad),
        jugadores(jugadores) {}

void EventoBuscarJugadores::resolver() {
    auto *estado = entidad->getComportamiento<EstadoDePersonajeServidor>("estado");

    auto *posicion = entidad->getEstado<Posicion>("posicion");
    auto posicionMasCercana = jugadores->posicionMasCercana(posicion);

    Posicion restaPosicion = posicion->menos(&posicionMasCercana);
    float mod = restaPosicion.modulo();
    if ( mod <= 700 ) {
        if( mod >= 200 ) {
            estado->caminar(entidad, restaPosicion.x <= 0, restaPosicion.x > 0, restaPosicion.y < 0,
                            restaPosicion.y > 0);
        }else{
            //TODO atacar
            int num = 1 + rand() % (101 - 1);
            if( restaPosicion.y <= 10 && restaPosicion.y >= -10 && num > 50){
                estado->golpear(entidad);
            }
        }
    }else{
        estado->reposar(entidad);
    }
}
