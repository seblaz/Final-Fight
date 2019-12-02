//
// Created by franco on 24/9/19.
//

#include "DandoGolpe.h"
#include "../../modelo/serializables/Arma.h"

void DandoGolpe::actualizar() {
    auto *velocidad = entidad->getEstado<Velocidad>("velocidad");

    velocidad->x = 0;
    velocidad->y = 0;

    if (framesFaltantes-- <= 0) {
        entidad->getEstado<Arma>("arma")->finUso();
        entidad->agregarComportamiento("estado", new EstadoDePersonajeServidor(entidad));
    }
}