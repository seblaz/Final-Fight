//
// Created by sebas on 10/9/19.
//

#include "FisicaDeEscenario.h"
#include "../servicios/Locator.h"
#include "../modelo/Mapa.h"
#include "../servidor/NivelServidor.h"

FisicaDeEscenario::FisicaDeEscenario(int largo) :
        largo(largo) {
    Configuracion *config = Locator::configuracion();
    scrollIzquierdo = config->getIntValue("/scroll/izquierdo");
    scrollDerecho = config->getIntValue("/scroll/derecho");
}

void FisicaDeEscenario::actualizar(Entidad *entidad) {
    auto *mapa = entidad->getEstado<Mapa>("mapa");
    int ancho = Locator::configuracion()->getIntValue("/resolucion/ancho");
    auto *posicionEscenario = entidad->getEstado<Posicion>("posicion");
    auto* xPersonaje = entidad->getEstado<Posicion>("posicion de jugador");
    int xMayorPersonaje = mapa->getJugadores()->getMayorX();
    int xMenorPersonaje = mapa->getJugadores()->getMenorX();
    xPersonaje->x = xMayorPersonaje;

    if ( xMayorPersonaje - xMenorPersonaje <= 800 ) {
        int xEscenario = posicionEscenario->getX();
        if ((xMayorPersonaje - xEscenario > ancho - scrollDerecho) && (largo - xMayorPersonaje) > scrollDerecho) {
            posicionEscenario->setX(xMayorPersonaje + scrollDerecho - ancho);
        }
        if ((xMenorPersonaje - xEscenario < scrollIzquierdo) && (xMenorPersonaje - scrollIzquierdo) > 0) {
            posicionEscenario->setX(xMenorPersonaje - scrollIzquierdo);
        }
    }
    if (xMayorPersonaje > largo) {
        Locator::logger()->log(INFO, "Se llego al final del nivel.");
        mapa->vaciarMapa();
        NivelServidor::generarNivel("nivel2", mapa);
    }
}