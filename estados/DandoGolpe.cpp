//
// Created by franco on 24/9/19.
//

#include "DandoGolpe.h"
#include "../modelo/envolventes/EnvolventeVolumen.h"
#include "../modelo/serializables/Orientacion.h"

void DandoGolpe::actualizar() {
    auto *velocidad = entidad->getEstado<Velocidad>("velocidad");

    velocidad->x = 0;
    velocidad->y = 0;

    if ( frame++ == frames_totales ) entidad->agregarComportamiento("estado", new EstadoDePersonajeServidor(entidad));
}