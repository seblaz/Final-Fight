//
// Created by sebas on 5/10/19.
//

#include "Eventos.h"

EventoAProcesar::EventoAProcesar(string msg) :
        msj_(std::move(msg)) {}

string EventoAProcesar::msj() {
    return msj_;
}

EventoATransmitir::EventoATransmitir(string msg) :
        msj_(std::move(msg)) {}

string EventoATransmitir::msj() {
    return msj_;
}
