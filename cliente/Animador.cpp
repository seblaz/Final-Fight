//
// Created by franco on 23/9/19.
//

#include "Animador.h"
#include "../modelo/serializables/EstadoDePersonaje.h"
#include "../graficos/FabricaDeAnimacionesCliente.h"

void Animador::actualizar(Entidad *entidad) {

    auto *estado = entidad->getEstado<EstadoDePersonaje>("estado de personaje");
    auto* fabricaDeAnimaciones = entidad->getEstado<FabricaDeAnimacionesCliente>("fabrica de animaciones");
    entidad->agregarEstado("animacion", fabricaDeAnimaciones->getAnimacion(estado->getEstado()));
}