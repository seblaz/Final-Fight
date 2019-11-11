//
// Created by franco on 8/9/19.
//

#include "Agachado.h"
#include "../servicios/Locator.h"
#include "../modelo/Velocidad.h"
#include "Saltando.h"

void Agachado::actualizar() {
    auto *velocidad = entidad->getEstado<Velocidad>("velocidad");
    velocidad->x = 0;
    velocidad->y = 0;
}
