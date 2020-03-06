//
// Created by franco on 3/11/19.
//

#include "RecibiendoGolpe.h"
#include "../../modelo/serializables/Energia.h"
#include "Muerto.h"

void RecibiendoGolpe::actualizar() {
    if (framesFaltantes-- <= 0) {
        auto *energia = entidad->getEstado<Energia>("energia");
        if (energia->conEnergia()) {
            entidad->agregarComportamiento("estado", new EstadoDePersonajeServidor(entidad));
        } else {
            entidad->getComportamiento<EstadoDePersonajeServidor>("estado")->morir();
        }
    }
    auto *velocidad = entidad->getEstado<Velocidad>("velocidad");
    velocidad->y = 0;
    velocidad->x = 0;
}
