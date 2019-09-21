//
// Created by sebas on 10/9/19.
//

#include "FisicaDeEscenario.h"
#include "../servicios/Locator.h"

void FisicaDeEscenario::actualizar(Entidad * entidad) {
    int ancho = Locator::configuracion()->getIntValue("/resolucion/ancho");
//    int xPersonaje = fisicaDePersonaje->posicion().getX();
//    // Mover el escenario.
//    if((xPersonaje - posicion_ < scrollIzquierdo) && (xPersonaje - scrollIzquierdo) > 0)
//        posicion_ = xPersonaje - scrollIzquierdo;
//    if((xPersonaje - posicion_ > ancho - scrollDerecho) && (largo_ - xPersonaje) > scrollDerecho)
//        posicion_ = xPersonaje + scrollDerecho - ancho;
}

FisicaDeEscenario::FisicaDeEscenario(int largo) : largo_(largo){}
