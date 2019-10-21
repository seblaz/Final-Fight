//
// Created by leandro on 7/10/19.
//

#include "Usuario.h"

#include <utility>

Usuario::Usuario(string usuario, string contrasenia) :
        valido_(false),
        socket(nullptr),
        personaje(nullptr),
        personajeSeleccionado(CODY),
        usuario(std::move(usuario)),
        contrasenia(std::move(contrasenia)),
        conectadoVoluntariamente(true){}

string Usuario::getUsuario() {
    return usuario;
}

string Usuario::getContrasenia() {
    return contrasenia;
}

void Usuario::setSocket(Socket *nuevoSocket) {
    socket = nuevoSocket;
}

Socket *Usuario::getSocket() {
    return socket;
}

bool Usuario::estaConectado() {
    return socket != nullptr;
}

void Usuario::desconectar() {
    socket = nullptr;
}

void Usuario::setValido(bool valido) {
    valido_ = valido;
}

bool Usuario::getValido() {
    return valido_;
}

void Usuario::setPersonaje(Entidad *pEntidad) {
    personaje = pEntidad;
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

bool Usuario::operator==(const Usuario &obj) {
    return usuario == obj.usuario;
}

void Usuario::serializar(ostream &stream) {
    serializarString(stream, usuario);
    serializarString(stream, contrasenia);
}

void Usuario::deserializar(istream &stream) {
    usuario = deserializarString(stream);
    contrasenia = deserializarString(stream);
}

void Usuario::desconectarVoluntariamente(){
    this->conectadoVoluntariamente = false;
}

bool Usuario::estaDesconectadoVoluntariamente(){
    return this->conectadoVoluntariamente;
}