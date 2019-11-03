//
// Created by franco on 29/10/19.
//

#include "buscarJugadores.h"

buscarJugadores::buscarJugadores(Jugadores *jugadores) {
    this -> jugadores = jugadores;
}

void buscarJugadores::actualizar(Entidad *entidad) {

    auto *estado = entidad->getComportamiento<EstadoDePersonajeServidor>("estado");
    //estado->actualizar(entidad);

    auto *posicion = entidad->getEstado<Posicion>("posicion");
    auto *posicionMasCercana = jugadores->posicionMasCercana(posicion);

    Posicion restaPosicion = posicion->menos(posicionMasCercana);
    float mod = restaPosicion.modulo();
    if ( mod <= 700 ) {
        if( mod >= 200 ) {
            estado->caminar(entidad, restaPosicion.x <= 0, restaPosicion.x > 0, restaPosicion.y < 0,
                            restaPosicion.y > 0);
        }else{
            //TODO atacar
            if( restaPosicion.y <= 10 && restaPosicion.y >= -10){
                estado->golpear(entidad);
            }
        }
    }else{
        estado->reposar(entidad);
    }
}
