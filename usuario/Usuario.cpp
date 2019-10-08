//
// Created by leandro on 7/10/19.
//

#include "Usuario.h"

Usuario::Usuario(string usuario, string contrasenia): usuario(usuario), contrasenia(contrasenia) {}

void Usuario::serializar(ostream &stream) {
    serializarString(stream, usuario);
    serializarString(stream, contrasenia);
}

void Usuario::deserializar(istream &stream) {
    usuario = deserializarString(stream);
    contrasenia = deserializarString(stream);
}
