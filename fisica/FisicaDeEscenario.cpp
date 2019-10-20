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
    ancho = Locator::configuracion()->getIntValue("/resolucion/ancho");
    xScrollIzquierdo = scrollIzquierdo;
    xScrollDerecho = ancho - scrollDerecho;
}

void FisicaDeEscenario::actualizar(Entidad *entidad) {
    auto *mapa = entidad->getEstado<Mapa>("mapa");
    auto *posicionEscenario = entidad->getEstado<Posicion>("posicion");
    auto* jugadores = mapa->getJugadores();
    int xMayorPersonaje = jugadores->getMayorX();
    int xMenorPersonaje = jugadores->getMenorX();
    int xEscenario = posicionEscenario->getX();
    xScrollIzquierdo = xEscenario + scrollIzquierdo;

    if ( xMayorPersonaje - xMenorPersonaje <= ancho - scrollDerecho - scrollIzquierdo) {
        if ((xMayorPersonaje - xEscenario > ancho - scrollDerecho) && (largo - xMayorPersonaje) > scrollDerecho) {
            posicionEscenario->setX(xMayorPersonaje + scrollDerecho - ancho);
            xScrollDerecho = xMayorPersonaje;
        }
        if ((xMenorPersonaje - xEscenario < scrollIzquierdo) && (xMenorPersonaje - scrollIzquierdo) > 0) {
            posicionEscenario->setX(xMenorPersonaje - scrollIzquierdo);
            xScrollDerecho = xEscenario + ancho - scrollDerecho;
        }
    }else {
        mapa->getJugadores()->bloquearMovientos(xScrollIzquierdo, xScrollDerecho);
    }
    jugadores->arrastrarInactivos(xScrollIzquierdo, xScrollDerecho);
    if (xMayorPersonaje > largo) {
        Locator::logger()->log(INFO, "Se llego al final del nivel.");
        mapa->vaciarMapa();
        NivelServidor::generarNivel("nivel2", mapa);
    }
}