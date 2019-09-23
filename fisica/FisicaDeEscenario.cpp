//
// Created by sebas on 10/9/19.
//

#include "FisicaDeEscenario.h"
#include "../servicios/Locator.h"
#include "../modelo/Posicion.h"

FisicaDeEscenario::FisicaDeEscenario(int largo) :
        largo(largo) {}

void FisicaDeEscenario::actualizar(Entidad *entidad) {
    int ancho = Locator::configuracion()->getIntValue("/resolucion/ancho", 0);
    auto *posicionEscenario = entidad->getEstado<Posicion>("posicion");
    int xPersonaje = entidad->getEstado<Posicion>("posicion de jugador")->getX();

    int xEscenario = posicionEscenario->getX();
    if ((xPersonaje - xEscenario < scrollIzquierdo) && (xPersonaje - scrollIzquierdo) > 0)
        posicionEscenario->setX(xPersonaje - scrollIzquierdo);
    if ((xPersonaje - xEscenario > ancho - scrollDerecho) && (largo - xPersonaje) > scrollDerecho)
        posicionEscenario->setX(xPersonaje + scrollDerecho - ancho);
}