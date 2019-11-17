//
// Created by franco on 17/11/19.
//

#include "BossIA.h"
#include "../../servicios/Locator.h"
#include "../personajes/EstadoDePersonajeServidor.h"

BossIA::BossIA(Entidad *entidad, Jugadores *jugadores):
    Comportamiento(entidad), jugadores(jugadores) {}

void BossIA::actualizar() {
    Locator::eventos()->push(new EventoBossIA(jugadores, entidad));
}

EventoBossIA::EventoBossIA(Jugadores *jugadores, Entidad *entidad)  :
        entidad(entidad),
        jugadores(jugadores) {}

void EventoBossIA::resolver() {
    auto *estado = entidad->getComportamiento<EstadoDePersonajeServidor>("estado");
    auto *estadoDePersonaje = entidad->getEstado<EstadoDePersonaje>("estado de personaje");

    auto *posicion = entidad->getEstado<Posicion>("posicion");
    auto posicionMasCercana = jugadores->posicionMasCercana(posicion);

    Posicion restaPosicion = posicion->menos(&posicionMasCercana);
    float mod = restaPosicion.modulo();
    float modX = restaPosicion.moduloX();
    float modY = restaPosicion.moduloY();
    int num = 1 + rand() % (101 - 1);
    if ( mod <= 700 ) {
        if( mod >= 200 ) {
            if( num > 85){
                estado->saltar();
            }else{
                estado->caminar(restaPosicion.x <= 0, restaPosicion.x > 0, restaPosicion.y < 0,
                                restaPosicion.y > 0);
            }
        }else{
            //TODO atacar
                if( num > 50 && modX >= 200 ){
                    estado->caminar(restaPosicion.x <= 0, restaPosicion.x > 0, restaPosicion.y < 0,
                                    restaPosicion.y > 0);
                }else if ( estadoDePersonaje->getEstado() == CAMINANDO && modX > 90 && modX < 120 && modY < 5){
                    estado->darGolpe();
                }else{
                    estado->caminar(restaPosicion.x > 0, restaPosicion.x <= 0, restaPosicion.y > 0,
                                    restaPosicion.y < 0);
                }

        }
    }else{
        estado->reposar();
    }

}
