//
// Created by franco on 31/10/19.
//

#include "FisicaDeColisiones.h"
#include "../modelo/Envolvente.h"
#include "../servicios/Locator.h"

void FisicaDeColisiones::actualizar(Entidad * entidad) {
    Locator::eventos()->push(new EventoColisiones(entidad));

}

void EventoColisiones::resolver() {
    auto colisionables = entidad->getEstado<Mapa>("mapa")->getColisionables();
    auto idEntidad = entidad->getEstado<Mapa>("mapa")->getIdEntidad(entidad);
    colisionables->calcularPosiblesColisiones(entidad, idEntidad);
}

EventoColisiones::EventoColisiones(Entidad * entidad) {
    this->entidad = entidad;
}
