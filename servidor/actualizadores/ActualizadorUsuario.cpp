//
// Created by sebas on 12/10/19.
//

#include "ActualizadorUsuario.h"
#include "../../usuario/Usuario.h"
#include "../../servicios/Locator.h"

ActualizadorUsuario::ActualizadorUsuario(EventosAProcesar *eventos, ManagerUsuarios *manager) :
        eventos(eventos),
        manager(manager) {}

void ActualizadorUsuario::interpretarStream(stringstream &s) {
    auto *nuevoUsuario = new Usuario;
    nuevoUsuario->deserializar(s);
    
    auto *crear = new ManejarUsuario(nuevoUsuario, manager);
    eventos->push(crear);
    fin_ = true;
}

bool ActualizadorUsuario::fin() {
    return fin_;
}

ManejarUsuario::ManejarUsuario(Usuario *usuario, ManagerUsuarios *manager) :
        usuario(usuario),
        manager(manager) {}

void ManejarUsuario::resolver() {
    string password = Locator::configuracion()->getValue("/password");

    if (password != usuario->getContrasenia()) {
        Locator::logger()->log(ERROR, "Se recibió una contraseña incorrecta.");
        pthread_exit(nullptr);
    } else if (!manager->estaPresente(usuario)) {
        Locator::logger()->log(DEBUG, "El usuario: " + usuario->getUsuario() + " no está presente.");
        // TODO: manejar juego lleno o mismo usuario.
        manager->agregarUsuario(usuario);
    }
}

