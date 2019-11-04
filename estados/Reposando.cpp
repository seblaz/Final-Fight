//
// Created by franco on 6/9/19.
//

#include "Reposando.h"
#include "../servicios/Locator.h"

Reposando::Reposando() {
    Logger* logger = Locator::logger();
    logger -> log(DEBUG, "Se instancio un objeto de clase Reposando");
}

Reposando::~Reposando() {
    Logger* logger = Locator::logger();
    logger -> log(DEBUG, "Se elimino un objeto de clase Reposando");
}

void Reposando::actualizar(Entidad *entidad) {
    auto* velocidad = entidad->getEstado<Velocidad>("velocidad");
    velocidad->x = 0;
    velocidad->y = 0;
}