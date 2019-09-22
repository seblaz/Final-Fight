//
// Created by sebas on 10/9/19.
//

#include "FisicaDeEscenario.h"
#include "../servicios/Locator.h"
#include "../modelo/Posicion.h"

void FisicaDeEscenario::actualizar(Entidad * entidad) {
    int ancho = Locator::configuracion()->getIntValue("/resolucion/ancho");
    auto *posicionEscenario = entidad->getEstado<Posicion>("posicion");
    int xPersonaje = entidad->getEstado<Posicion>("posicion de jugador")->getX();
//    int xPersonaje = fisicaDePersonaje->posicion().getX();
//    // Mover el escenario.
    int xEscenario = posicionEscenario->getX();
    if((xPersonaje - xEscenario < scrollIzquierdo) && (xPersonaje - scrollIzquierdo) > 0)
        posicionEscenario->setX(xPersonaje - scrollIzquierdo);
    if((xPersonaje - xEscenario > ancho - scrollDerecho) && (5600 - xPersonaje) > scrollDerecho)
        posicionEscenario->setX(xPersonaje + scrollDerecho - ancho);
}


