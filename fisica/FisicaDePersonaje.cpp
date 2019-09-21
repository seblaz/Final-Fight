//
// Created by sebas on 2/9/19.
//

#include "FisicaDePersonaje.h"

void FisicaDePersonaje::actualizar(Entidad *entidad) {
    auto* velocidad = entidad->getEstado<Velocidad>();
    auto* posicion = entidad->getEstado<Posicion>();
    posicion->mover(*velocidad);
}
