//
// Created by franco on 6/9/19.
//

#include "Reposando.h"
#include "../servicios/Locator.h"
#include "../graficos/FabricaDeAnimacionesDeCody.h"

Reposando::Reposando() {
    Logger* logger = Locator::logger();
    logger -> log(DEBUG, "Se instancio un objeto de clase Parado");
}

Reposando::~Reposando() {
    Logger* logger = Locator::logger();
    logger -> log(DEBUG, "Se instancio un objeto de clase Parado");
}


void Reposando::enter(Entidad *entidad) {
    auto* animacion = FabricaDeAnimacionesDeCody::parado();
    entidad->agregarEstado("animacion", animacion);
}

void Reposando::actualizar(Entidad *entidad) {
    auto* velocidad = entidad->getEstado<Velocidad>("velocidad");
    velocidad->x = 0;
    velocidad->y = 0;
}