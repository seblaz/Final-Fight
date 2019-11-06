//
// Created by sebas on 1/11/19.
//

#include "ManagerPantallas.h"
#include "../../servicios/Locator.h"

void ManagerPantallas::agregarPantalla(Pantalla *pantalla) {
    if (pantallas.empty()) {
        {
            unique_lock<std::mutex> lock(m);
            actual = pantalla;
        }
    }
    pantallas[pantalla->getId()] = pantalla;
    pantalla->setManager(this);
}

void ManagerPantallas::cambiarA(const IdPantalla &idPantalla) {
    if (!idPantalla.empty()) {
        {
            unique_lock<std::mutex> lock(m);
            if(actual->getId() != idPantalla){
                actual = pantallas[idPantalla];
                Locator::logger()->log(INFO, "Se cambia a la pantalla: " + idPantalla + ".");
            }
        }
    }
}

Pantalla *ManagerPantallas::getActual() {
    unique_lock<std::mutex> lock(m);
    return actual;
}

