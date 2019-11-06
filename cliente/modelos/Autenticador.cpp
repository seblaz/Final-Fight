//
// Created by sebas on 1/11/19.
//

#include "Autenticador.h"
#include "../../modelo/serializables/Accion.h"
#include "../../usuario/Usuario.h"
#include "../../servicios/Locator.h"

void Autenticador::ingresar(char *i) {
    campoActivo->append(i);
}

void Autenticador::borrar() {
    if (!campoActivo->empty())
        campoActivo->pop_back();
}

void Autenticador::cambiarCampo() {
    campoActivo = campoActivo == &user ? &pass : &user;
}

string Autenticador::getUsuario() {
    return user;
}

string Autenticador::getPassword() {
    return pass;
}
