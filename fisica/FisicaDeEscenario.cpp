//
// Created by sebas on 10/9/19.
//

#include "FisicaDeEscenario.h"

void FisicaDeEscenario::actualizar() {
    int ancho = Locator::configuracion()->anchoDePantalla;
    int xPersonaje = fisicaDePersonaje.posicion().getX();
    // Mover el escenario.
    if((xPersonaje - posicion_ > ancho - scrollDerecho) && (xPersonaje + scrollDerecho - ancho) > 0)
        posicion_ = xPersonaje + scrollDerecho - ancho;
    if((xPersonaje - posicion_ < scrollIzquierdo) && (xPersonaje + scrollDerecho - ancho) > 0)
        posicion_ = xPersonaje - scrollIzquierdo;

    // Mover al personaje (turbio). TODO: mejorarlo.
    if(xPersonaje < scrollIzquierdo)
        fisicaDePersonaje.posicion().setX(scrollIzquierdo);
    if(xPersonaje > largo_ - scrollDerecho)
        fisicaDePersonaje.posicion().setX(largo_ - scrollDerecho);
}

int FisicaDeEscenario::posicion() {
    return posicion_;
}

FisicaDeEscenario::FisicaDeEscenario(FisicaDePersonaje &fisicaDePersonaje, int largo) :
        fisicaDePersonaje(fisicaDePersonaje), largo_(largo) {}
