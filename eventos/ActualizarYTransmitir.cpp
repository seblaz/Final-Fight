//
// Created by sebas on 7/10/19.
//

#include <iostream>
#include "ActualizarYTransmitir.h"
#include "../servicios/Locator.h"

ActualizarYTransmitir::ActualizarYTransmitir(Mapa *mapa, EventosATransmitir *eventosATransmitir) :
        mapa(mapa), eventosATransmitir(eventosATransmitir) {}

void ActualizarYTransmitir::resolver() {
    // TODO: actualizar.
    stringstream s = serializar();
    transmitir(s);
}

stringstream ActualizarYTransmitir::serializar() {
//    Locator::logger()->log(DEBUG, "Se serializa el modelo.");
    stringstream s;
    for(auto tupla : mapa->devolverEntidadesConId()){
        Entidad::putIdInStream(s, tupla.first);
        tupla.second->serializar(s);
    }
    return s;
}

void ActualizarYTransmitir::transmitir(stringstream &s) {
    auto *trasmision = new EventoATransmitir(s.str());
    eventosATransmitir->push(trasmision);
//    Locator::logger()->log(DEBUG, "Se transmite el modelo.");
}

