//
// Created by sebas on 12/10/19.
//

#include "ActualizadorUsuario.h"
#include "../../usuario/Usuario.h"
#include "../../servicios/Locator.h"

ActualizadorUsuario::ActualizadorUsuario(ManagerUsuarios *manager) : manager(manager) {}

void ActualizadorUsuario::interpretarStream(stringstream &s) {
    Usuario nuevoUsuario;
    nuevoUsuario.deserializar(s);

    string password = Locator::configuracion()->getValue("/password");

    if (password != nuevoUsuario.getContrasenia()) {
        Locator::logger()->log(ERROR, "Se recibió una contraseña incorrecta.");
        pthread_exit(nullptr);
    } else if(!manager->estaPresente(&nuevoUsuario)){
        Locator::logger()->log(DEBUG, "El usuario: " + nuevoUsuario.getUsuario() + " no está presente.");
        // TODO: manejar juego lleno o mismo usuario.
        manager->agregarUsuario(&nuevoUsuario);
    }
    fin_ = true;
}

bool ActualizadorUsuario::fin() {
    return fin_;
}