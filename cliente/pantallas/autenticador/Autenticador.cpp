//
// Created by sebas on 1/11/19.
//

#include "Autenticador.h"
#include "../../../modelo/serializables/Accion.h"
#include "../../../usuario/Usuario.h"
#include "../../../servicios/Locator.h"

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

EVENTO_USUARIO Autenticador::confirmar() {
    Socket *socket = Locator::socket();

    stringstream userStream;
    Accion enviarUsuario(ENVIAR_USUARIO);
    enviarUsuario.serializar(userStream);

    Usuario usuario(user, pass);
    usuario.serializar(userStream);
    socket->enviar(userStream);

    stringstream streamEvento;
    socket->recibir(streamEvento);
    EventoUsuario evento;
    evento.deserializar(streamEvento);

    user = "";
    pass = "";
    campoActivo = &user;

    return evento.evento();
}

string Autenticador::getUsuario() {
    return user;
}

string Autenticador::getPassword() {
    return pass;
}
