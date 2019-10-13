//
// Created by sebas on 12/10/19.
//

#include "ActualizadorUsuario.h"
#include "../../usuario/Usuario.h"
#include "../../servicios/Locator.h"
#include <unistd.h>

ActualizadorUsuario::ActualizadorUsuario(EventosAProcesar *eventos, ManagerUsuarios *manager) :
        usuarioAgregado(0),
        eventos(eventos),
        manager(manager) {}

Usuario *ActualizadorUsuario::interpretarStream(stringstream &s, Socket socket) {
    auto *nuevoUsuario = new Usuario;
    nuevoUsuario->deserializar(s);

    string password = Locator::configuracion()->getValue("/password");
    if (password != nuevoUsuario->getContrasenia()) {
        Locator::logger()->log(ERROR, "Se recibió una contraseña incorrecta.");
        close(socket.getIntSocket());
        pthread_exit(nullptr);
    }

    auto *crear = new AgregarUsuario(nuevoUsuario, manager, usuarioAgregado);
    eventos->push(crear);
    usuarioAgregado.wait();
    fin_ = true;
    return nuevoUsuario;
}

bool ActualizadorUsuario::fin() {
    return fin_;
}

AgregarUsuario::AgregarUsuario(Usuario *usuario, ManagerUsuarios *manager, semaphore &semaphore) :
        usuarioAgregado(semaphore),
        usuario(usuario),
        manager(manager) {}

void AgregarUsuario::resolver() {
    manager->agregarUsuario(usuario);
    usuarioAgregado.post();
}

