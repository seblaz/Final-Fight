//
// Created by sebas on 7/10/19.
//

#include <iostream>
#include "ActualizarYSerializarMapa.h"
#include "../servicios/Locator.h"

ActualizarYSerializarMapa::ActualizarYSerializarMapa(Mapa *mapa) :
        mapa(mapa) {}

void ActualizarYSerializarMapa::resolver() {
    actualizar();
    serializar();
}

void ActualizarYSerializarMapa::actualizar() {
    for (auto entidad : mapa->devolverEntidades()) {
        auto comportamientos = entidad->getComportamientos();
        for (auto *comportamiento : comportamientos) {
            comportamiento->actualizar();
        }
    }
    auto *colisionables = Locator::colisionables();
    colisionables->calcularPosiblesColisiones();
    colisionables->calcularAtaquesDeJugadoresAEnemigos();
    colisionables->calcularAtaquesAelementos();
    colisionables->calcularArmasAlcanzables();
}

void ActualizarYSerializarMapa::serializar() {
    stringstream s;
    for(auto tupla : mapa->devolverEntidadesConId()){
        Entidad::putIdInStream(s, tupla.first);
        tupla.second->serializar(s);
    }
    mapa->guardarSerializado(s);
}