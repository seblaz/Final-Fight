//
// Created by sebas on 10/9/19.
//

#include "FisicaDeEscenario.h"
#include "../servicios/Locator.h"
#include "../modelo/Mapa.h"
#include "../servidor/NivelServidor.h"
#include "../modelo/serializables/Nivel.h"

FisicaDeEscenario::FisicaDeEscenario(int largo) :
        largo(largo) {
    Configuracion *config = Locator::configuracion();
    scrollIzquierdo = config->getIntValue("/scroll/izquierdo");
    scrollDerecho = config->getIntValue("/scroll/derecho");
    ancho = config->getIntValue("/resolucion/ancho");
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

    if ( xMayorPersonaje - xMenorPersonaje <= ancho - scrollDerecho - scrollIzquierdo && xMenorPersonaje >= xScrollIzquierdo) {
        if ((xMayorPersonaje - xEscenario > ancho - scrollDerecho) && (largo - xMayorPersonaje) > scrollDerecho) {
            posicionEscenario->setX(xMayorPersonaje + scrollDerecho - ancho);
            if ( xMayorPersonaje > xScrollDerecho )
                xScrollDerecho = xMayorPersonaje;
        }
        if ((xMenorPersonaje - xEscenario < scrollIzquierdo) && (xMenorPersonaje - scrollIzquierdo) > 0) {
            posicionEscenario->setX(xMenorPersonaje - scrollIzquierdo);
            if ( xEscenario + ancho - scrollDerecho > xScrollDerecho )
                xScrollDerecho = xEscenario + ancho - scrollDerecho;
        }
    }else if ( largo - ancho <= posicionEscenario->x + 10) {
        jugadores->bloquearMovimientos(xScrollIzquierdo, largo + 1);
    }else {
        jugadores->bloquearMovimientos(xScrollIzquierdo, xScrollDerecho);
    }
    jugadores->arrastrarInactivos(xScrollIzquierdo, xScrollDerecho);
    if (xMayorPersonaje > largo) {
        mapa->vaciarMapa();
        auto *nivel = entidad->getEstado<Nivel>("nivel");
        Locator::logger()->log(INFO, "Se llego al final del " + nivel->nivel() + " .");
        string proxEtapa = nivel->nivel() == "nivel1" ? "puntuacion1" : "puntuacion2";
        Locator::clientes()->cambiarTodosA(proxEtapa);
    }
}