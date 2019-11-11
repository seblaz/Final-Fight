//
// Created by franco on 3/11/19.
//

#include "RecibiendoGolpe.h"

RecibiendoGolpe::RecibiendoGolpe() {

}

RecibiendoGolpe::~RecibiendoGolpe() {
    Logger* logger = Locator::logger();
    logger -> log(DEBUG, "Se elimino un objeto de clase RecibiendoGolpe");
}

void RecibiendoGolpe::actualizar(Entidad * entidad) {
    auto *velocidad = entidad->getEstado<Velocidad>("velocidad");
    velocidad->x = 0;
    velocidad->y = 0;
}
