//
// Created by sebas on 5/11/19.
//

#include "InterpreteServidor.h"
#include "../../servicios/Locator.h"

InterpreteServidor::InterpreteServidor(Usuario *usuario) :
        usuario(usuario) {}

bool InterpreteServidor::interpretarStream(stringstream &s) {
    Accion accion;
    accion.deserializar(s);
    switch (accion.accion()) {
        case FIN:
            desconectarUsuario();
            return false;
        case NULA:
            return true;
    }
    return interpretarAccion(accion.accion(), s);
}

Usuario *InterpreteServidor::getUsuario() {
    return usuario;
}

void InterpreteServidor::desconectarUsuario() {
    if (usuario) {
        Locator::logger()->log(INFO, "Se desconecta voluntariamente el usuario " + usuario->getUsuario() + ".");
        Locator::eventos()->push(new DesconectarVoluntariamente(usuario));
    } else {
        Locator::logger()->log(INFO, "Se desconecta un cliente que no pasó la etapa de usuario.");
    }
}

DesconectarVoluntariamente::DesconectarVoluntariamente(Usuario *usuario) :
        usuario(usuario) {}

void DesconectarVoluntariamente::resolver() {
    usuario->desconectarVoluntariamente();
}
