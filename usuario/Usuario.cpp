//
// Created by leandro on 7/10/19.
//

#include "Usuario.h"

Usuario::Usuario(string usuario, string contrasenia) : usuario(usuario), contrasenia(contrasenia) {}

void Usuario::serializar(ostream &stream) {
    serializarString(stream, usuario);
    serializarString(stream, contrasenia);
}

void Usuario::deserializar(istream &stream) {
    usuario = deserializarString(stream);
    contrasenia = deserializarString(stream);
}

string Usuario::getUsuario() {
    return usuario;
}

string Usuario::getContrasenia() {
    return contrasenia;
}

void Usuario::setSocket(Socket *nuevoSocket) {
    socket = nuevoSocket;
}

void Usuario::setPersonaje(Entidad *pEntidad) {
    personaje = pEntidad;
}

Socket *Usuario::getSocket() {
    return socket;
}

Entidad *Usuario::getPersonaje() {
    return personaje;
}

void Usuario::setPersonajeSeleccionado(
        enum PERSONAJE personajeSeleccionado_) {
    personajeSeleccionado = personajeSeleccionado_;
};

enum PERSONAJE Usuario::getPersonajeSeleccionado() {
    return personajeSeleccionado;
}