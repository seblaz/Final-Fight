//
// Created by sebas on 10/9/19.
//

#include "FisicaDeEscenario.h"

void FisicaDeEscenario::actualizar() {
    int ancho = Locator::configuracion()->anchoDePantalla;
    if((fisicaDePersonaje.posicion().getX() - posicion_ > ancho - scrollDerecho))
        posicion_ = fisicaDePersonaje.posicion().getX() + scrollDerecho - ancho;
    if(fisicaDePersonaje.posicion().getX() - posicion_ < scrollIzquierdo)
        posicion_ = fisicaDePersonaje.posicion().getX() - scrollIzquierdo;
}

int FisicaDeEscenario::posicion() {
    return posicion_;
}

FisicaDeEscenario::FisicaDeEscenario(FisicaDePersonaje &fisicaDePersonaje) :
        fisicaDePersonaje(fisicaDePersonaje) {}
