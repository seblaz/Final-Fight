//
// Created by sebas on 2/9/19.
//

#include "FisicaDePersonaje.h"
#include "../modelo/Orientacion.h"

void FisicaDePersonaje::actualizar(Entidad *entidad) {
    auto* velocidad = entidad->getEstado<Velocidad>();
    auto* posicion = entidad->getEstado<Posicion>();
    auto* orientacion = entidad->getEstado<Orientacion>();
    posicion->mover(*velocidad);
    orientacion->adelante = velocidad->x != 0 ? velocidad->x > 0 : orientacion->adelante;
}
