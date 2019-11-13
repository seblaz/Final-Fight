//
// Created by franco on 3/11/19.
//

#include "RecibiendoGolpe.h"

void RecibiendoGolpe::actualizar() {
    if (faltante-- <= 0) entidad->agregarComportamiento("estado", new EstadoDePersonajeServidor(entidad));
    auto *velocidad = entidad->getEstado<Velocidad>("velocidad");
    velocidad->y = 0;
    velocidad->x = 0;
}
