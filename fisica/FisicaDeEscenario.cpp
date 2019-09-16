//
// Created by sebas on 10/9/19.
//

#include "FisicaDeEscenario.h"

void FisicaDeEscenario::actualizar() {
    int ancho = Locator::configuracion()->anchoDePantalla;
    if(fisicaDePersonaje.posicion().getX() - posicion_ > ancho - scroll)
        posicion_ = fisicaDePersonaje.posicion().getX() + scroll - ancho;
}

int FisicaDeEscenario::posicion() {
    return posicion_;
}

FisicaDeEscenario::FisicaDeEscenario(FisicaDePersonaje &fisicaDePersonaje) :
        fisicaDePersonaje(fisicaDePersonaje) {}
