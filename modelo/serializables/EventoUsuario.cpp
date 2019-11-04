//
// Created by sebas on 18/10/19.
//

#include "EventoUsuario.h"

EventoUsuario::EventoUsuario() :
        evento_(CONTRASENIA_INCORRECTA) {}

EventoUsuario::EventoUsuario(EVENTO_USUARIO evento) :
        evento_(evento) {}

EVENTO_USUARIO EventoUsuario::evento() {
    return evento_;
}

void EventoUsuario::serializar(ostream &stream) {
    serializarEntero(stream, evento_);
}

void EventoUsuario::deserializar(istream &stream) {
    evento_ = static_cast<EVENTO_USUARIO>(deserializarEntero(stream));
}