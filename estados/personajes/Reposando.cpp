//
// Created by franco on 6/9/19.
//

#include "Reposando.h"
#include "../../servicios/Locator.h"

void Reposando::actualizar() {
    auto* velocidad = entidad->getEstado<Velocidad>("velocidad");
    velocidad->x = 0;
    velocidad->y = 0;
}