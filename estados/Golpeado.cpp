//
// Created by franco on 3/11/19.
//

#include "Golpeado.h"

Golpeado::Golpeado() {

}

Golpeado::~Golpeado() {
    Logger* logger = Locator::logger();
    logger -> log(DEBUG, "Se elimino un objeto de clase Golpeado");
}

void Golpeado::actualizar(Entidad * entidad) {
    auto *velocidad = entidad->getEstado<Velocidad>("velocidad");
    velocidad->x = 0;
    velocidad->y = 0;
}
