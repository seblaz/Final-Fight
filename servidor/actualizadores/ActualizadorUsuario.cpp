//
// Created by sebas on 12/10/19.
//

#include "ActualizadorUsuario.h"
#include "../../usuario/Usuario.h"
#include "../../servicios/Locator.h"
#include "../../modelo/EventoUsuario.h"
#include <unistd.h>

ActualizadorUsuario::ActualizadorUsuario(EventosAProcesar *eventos, ManagerUsuarios *manager) :
        usuarioAgregado(0),
        eventos(eventos),
        manager(manager) {}

Usuario *ActualizadorUsuario::getUsuario(Socket socket) {
    auto *nuevoUsuario = new Usuario;

    // Chequear contraseña
    string password = Locator::configuracion()->getValue("/password");
    stringstream s;
    bool contraseniaCorrecta;
    do {
        if (!socket.recibir(s)) {
            Locator::logger()->log(ERROR, "Se termina el hilo.");
            pthread_exit(nullptr);
        }
        nuevoUsuario->deserializar(s);
        contraseniaCorrecta = (password == nuevoUsuario->getContrasenia());
        if (!contraseniaCorrecta){
            Locator::logger()->log(ERROR, "Se recibió una contraseña incorrecta del usuario: " + nuevoUsuario->getUsuario() + ".");
            EventoUsuario evento(CONTRASENIA_INCORRECTA);
            stringstream ss;
            evento.serializar(ss);
            socket.enviar(ss);
        }
    } while (!contraseniaCorrecta);

    Locator::logger()->log(DEBUG, "Se recibió una contraseña correcta del usuario: " + nuevoUsuario->getUsuario() + ".");

    // Chequear usuario
    nuevoUsuario->setSocket(&socket);
    auto *crear = new AgregarUsuario(nuevoUsuario, manager, usuarioAgregado);
    eventos->push(crear);
    usuarioAgregado.wait();

    if (nuevoUsuario->valido()) {
        Locator::logger()->log(INFO, "El usuario: " + nuevoUsuario->getUsuario() + " es válido e ingresa a la partida.");
        return nuevoUsuario;
    } else {
        Locator::logger()->log(INFO, "El usuario: " + nuevoUsuario->getUsuario() + " es inválido y se termina su hilo.");
        pthread_exit(nullptr);
    }
}

AgregarUsuario::AgregarUsuario(Usuario *usuario, ManagerUsuarios *manager, semaphore &semaphore) :
        usuarioAgregado(semaphore),
        usuario(usuario),
        manager(manager) {}

void AgregarUsuario::resolver() {
    manager->administrarUsuario(usuario);
    usuarioAgregado.post();
}

