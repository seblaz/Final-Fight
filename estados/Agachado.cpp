//
// Created by franco on 8/9/19.
//

#include "Agachado.h"
#include "../servicios/Locator.h"
#include "../modelo/Velocidad.h"
#include "Saltando.h"
#include "../graficos/FabricaDeAnimacionesDeCody.h"

Agachado::Agachado() {
    Logger *logger = Locator::logger();
    logger->log(DEBUG, "Se instancio un objeto de clase Agachado");
}

Agachado::~Agachado() {
    Logger *logger = Locator::logger();
    logger->log(DEBUG, "Se elimino un objeto de clase Agachado");
}


void Agachado::enter(Entidad *entidad) {
    auto *animacion = FabricaDeAnimacionesDeCody::agachado();
    entidad->agregarEstado("animacion", animacion);
}

void Agachado::actualizar(Entidad *entidad) {
    auto *velocidad = entidad->getEstado<Velocidad>("velocidad");
    velocidad->x = 0;
    velocidad->y = 0;
}
