//
// Created by franco on 13/9/19.
//

#include "Caminando.h"
#include "../servicios/Locator.h"
#include "../graficos/FabricaDeAnimacionesDeCody.h"

Caminando::Caminando() {
    Logger* logger = Locator::logger();
    logger -> log(DEBUG, "Se instancio un objeto de clase Caminando");
}

Caminando::~Caminando() {
    Logger* logger = Locator::logger();
    logger -> log(DEBUG, "Se instancio un objeto de clase Caminando");
}

#define RAPIDEZ 4

void Caminando::enter(Entidad * entidad) {
    auto* animacion = FabricaDeAnimacionesDeCody::caminando();
    entidad->agregarEstado("animacion", animacion);
}


