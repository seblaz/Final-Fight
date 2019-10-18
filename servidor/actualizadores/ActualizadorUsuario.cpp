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

    if (!nuevoUsuario->getValido()) {
        pthread_exit(nullptr);
    }
    return nuevoUsuario;
}

AgregarUsuario::AgregarUsuario(Usuario *usuario, ManagerUsuarios *manager, semaphore &semaphore) :
        usuarioAgregado(semaphore),
        usuario(usuario),
        manager(manager) {}

void AgregarUsuario::resolver() {
    EventoUsuario *evento;
    if(manager->estaPresente(usuario)){
        Usuario *usuarioAnterior = manager->getUsuarioAnterior(usuario);

        if(usuarioAnterior->estaConectado()){ // El usuario esta conectado desde otro cliente.
            usuario->setValido(false);
            evento = new EventoUsuario(USUARIO_YA_CONECTADO);
            Locator::logger()->log(ERROR, "El usuario: " + usuarioAnterior->getUsuario() + " se encuentra conectado desdo otro cliente.");

        } else { // El usuario se había desconectado.
            usuario->setPersonaje(usuarioAnterior->getPersonaje());
            manager->reemplazarUsuarioCon(usuario);
            usuario->setValido(true);
            evento = new EventoUsuario(CONECTADO);
            Locator::logger()->log(INFO, "El usuario: " + usuarioAnterior->getUsuario() + " se reconectó a la partida.");
        }
    } else {
        if (manager->faltanJugadores()){ // Hay espacio para un jugador más.
            manager->agregarUsuario(usuario);
            usuario->setValido(true);
            evento = new EventoUsuario(CONECTADO);
            Locator::logger()->log(INFO, "El usuario: " + usuario->getUsuario() + " se conectó a la partida.");

        } else { // No queda espacio en la partida
            Locator::logger()->log(ERROR, "El usuario: " + usuario->getUsuario() + " trató de conectarse cuando la partida ya estaba completa.");
            usuario->setValido(false);
            evento = new EventoUsuario(PARTIDA_LLENA);
        }
    }
    stringstream ss;
    evento->serializar(ss);
    usuario->getSocket()->enviar(ss);
    usuarioAgregado.post();
}

