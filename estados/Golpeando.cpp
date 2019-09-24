//
// Created by franco on 24/9/19.
//

#include "Golpeando.h"

Golpeando::Golpeando() {
    Logger* logger = Locator::logger();
    logger -> log(DEBUG, "Se instancio un objeto de clase Golpeando");
}

Golpeando::~Golpeando() {
    Logger* logger = Locator::logger();
    logger -> log(DEBUG, "Se elimino un objeto de clase Golpeando");
}

void Golpeando::enter(Entidad *entidad) {
    auto* animacion = FabricaDeAnimacionesDeCody::golpear();
    entidad->agregarEstado("animacion", animacion);
}

void Golpeando::actualizar(Entidad * entidad) {
    auto *velocidad = entidad->getEstado<Velocidad>("velocidad");
    velocidad->x = 0;
    velocidad->y = 0;
}

