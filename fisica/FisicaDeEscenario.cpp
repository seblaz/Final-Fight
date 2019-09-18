//
// Created by sebas on 10/9/19.
//

#include "FisicaDeEscenario.h"

void FisicaDeEscenario::actualizar() {
    int ancho = Locator::configuracion()->getIntValue("/resolucion/ancho");
    int xPersonaje = fisicaDePersonaje.posicion().getX();
    // Mover el escenario.
    if((xPersonaje - posicion_ < scrollIzquierdo) && (xPersonaje - scrollIzquierdo) > 0)
        posicion_ = xPersonaje - scrollIzquierdo;
    if((xPersonaje - posicion_ > ancho - scrollDerecho) && (largo_ - xPersonaje) > scrollDerecho)
        posicion_ = xPersonaje + scrollDerecho - ancho;
}

int FisicaDeEscenario::posicion() {
    return posicion_;
}

FisicaDeEscenario::FisicaDeEscenario(FisicaDePersonaje &fisicaDePersonaje, int largo) :
        fisicaDePersonaje(fisicaDePersonaje), largo_(largo) {}
