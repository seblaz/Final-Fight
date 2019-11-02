//
// Created by sebas on 1/11/19.
//

#include "ManagerPantallas.h"

void ManagerPantallas::agregarPantalla(Pantalla *pantalla) {
    if(pantallas.empty())
        actual = pantalla;
    pantallas[pantalla->getId()] = pantalla;
    pantalla->setManager(this);
}

void ManagerPantallas::cambiarA(const IdPantalla& idPantalla) {
    if(!idPantalla.empty()) {
        actual = pantallas[idPantalla];
        actual->iniciar();
    }
}

Pantalla *ManagerPantallas::getActual() {
    return actual;
}

