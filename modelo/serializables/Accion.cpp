//
// Created by sebas on 8/10/19.
//

#include "Accion.h"

Accion::Accion() : accion_(CONFIRMAR){}

Accion::Accion(ACCION accion) : accion_(accion){}

ACCION Accion::accion() {
    return accion_;
}

void Accion::serializar(ostream &stream) {
    serializarEntero(stream, accion_);
}

void Accion::deserializar(istream &stream) {
    accion_ = static_cast<ACCION>(deserializarEntero(stream));
}

AccionEnviarUsuario::AccionEnviarUsuario(Usuario *usuario) :
        usuario(usuario),
        Accion(ENVIAR_USUARIO) {}

void AccionEnviarUsuario::serializar(ostream &stream) {
    Accion::serializar(stream);
    usuario->serializar(stream);
}
