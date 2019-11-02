//
// Created by sebas on 1/11/19.
//

#include "Pantalla.h"

#include <utility>
#include "ManagerPantallas.h"

Pantalla::Pantalla(IdPantalla id) :
    id(std::move(id)) {}

IdPantalla Pantalla::getId() {
    return id;
}

void Pantalla::setManager(ManagerPantallas *manager_) {
    manager = manager_;
}
