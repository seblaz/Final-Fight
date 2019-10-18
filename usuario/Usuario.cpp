//
// Created by leandro on 7/10/19.
//

#include "Usuario.h"

#include <utility>

Usuario::Usuario(string usuario, string contrasenia) :
        valido_(false),
        socket(nullptr),
        personaje(nullptr),
        usuario(std::move(usuario)),
        contrasenia(std::move(contrasenia)) {}

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

bool Usuario::operator==(const Usuario &obj) {
    return usuario == obj.usuario;
}

void Usuario::setPersonajeSeleccionado(
        enum PERSONAJE personajeSeleccionado_) {
    personajeSeleccionado = personajeSeleccionado_;
};

enum PERSONAJE Usuario::getPersonajeSeleccionado() {
    return personajeSeleccionado;
}

bool Usuario::valido() {
    return valido_;
}

void Usuario::setValido(bool valido) {
    valido_ = valido;
}

