//
// Created by sebas on 5/10/19.
//

#include "Evento.h"

Evento::Evento(string msg, void (*accion)()) :
        accion(accion),
        msg(std::move(msg)) {}

void Evento::resolver() {
    (*accion)();
}

void accionNula() {};