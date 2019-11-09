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

    //auto* mapa = Locator::mapa();
    //auto colisionables = mapa->getColisionables();
    //colisionables->calcularPosiblesColisiones(entidad);
}

EventoColisiones::EventoColisiones(Entidad * entidad) {
    this->entidad = entidad;
}
