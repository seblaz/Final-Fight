//
// Created by franco on 6/9/19.
//

#include "Parado.h"
#include "../servicios/Locator.h"
#include "../graficos/FabricaDeAnimacionesDeCody.h"

Parado::Parado() {
    Logger* logger = Locator::logger();
    logger -> log(DEBUG, "Se instancio un objeto de clase Parado");
}

Parado::~Parado() {
    Logger* logger = Locator::logger();
    logger -> log(DEBUG, "Se instancio un objeto de clase Parado");
}


void Parado::enter(Entidad *entidad) {
    auto* animacion = FabricaDeAnimacionesDeCody::parado();
    entidad->agregarEstado("animacion", animacion);
}
