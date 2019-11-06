//
// Created by sebas on 5/11/19.
//

#include "InterpreteAutenticacionServ.h"
#include "../../servicios/Locator.h"

InterpreteAutenticacionServ::InterpreteAutenticacionServ(Usuario *usuario, ModeloAutenticacion *autenticacion) :
        usuarioAgregado(0),
        InterpreteServidor(usuario),
        autenticacion(autenticacion) {}

bool InterpreteAutenticacionServ::interpretarAccion(ACCION accion, stringstream &s) {
    if(accion == ENVIAR_USUARIO){
        getUsuario()->deserializar(s);
        if (!validarContrasenia(getUsuario())) return true;

        auto *crear = new AgregarUsuario(getUsuario(), autenticacion, usuarioAgregado, getEtapa()->getManager());
        Locator::eventos()->push(crear);
        usuarioAgregado.wait();

        if (!getUsuario()->getValido()) { // Usuario invalido
            Locator::logger()->log(INFO, "Se desconecta un cliente que no pasó la etapa de autenticación.");
            return false;
        }

        return true;
    } else {
        Locator::logger()->log(ERROR, "Se recibió una acción inválida en el actualizador de usuario.");
    }
    return false;
}

bool InterpreteAutenticacionServ::validarContrasenia(Usuario *usuario) {
    if (Locator::usuarios()->validarContrasenia(usuario)) {
        Locator::logger()->log(INFO, "Se recibió una contraseña correcta del usuario: " + usuario->getUsuario() + ".");
        return true;
    }

    Locator::logger()->log(ERROR, "Se recibió una contraseña incorrecta del usuario: " + usuario->getUsuario() + ".");
    autenticacion->passwordIncorrecta();
    return false;
}

AgregarUsuario::AgregarUsuario(Usuario *usuario, ModeloAutenticacion *autenticacion, semaphore &semaphore,
                               ManagerEtapas *etapas) :
        etapas(etapas),
        usuario(usuario),
        usuarioAgregado(semaphore),
        autenticacion(autenticacion) {}

void AgregarUsuario::resolver() {
    ManagerUsuarios *manager = Locator::usuarios();
    if (manager->estaPresente(usuario)) {
        Usuario *usuarioAnterior = manager->getUsuarioAnterior(usuario);

        if (usuarioAnterior->estaConectado()) { // El usuario esta conectado desde otro cliente.
            usuario->setValido(false);
            Locator::logger()->log(ERROR, "El usuario: " + usuarioAnterior->getUsuario() + " se encuentra conectado desdo otro cliente.");
            autenticacion->usuarioYaConectado();

        } else { // El usuario se había desconectado.
            usuario->setPersonaje(usuarioAnterior->getPersonaje());
            manager->reemplazarUsuarioCon(usuario);
            usuario->setValido(true);
            Locator::logger()->log(INFO, "El usuario: " + usuarioAnterior->getUsuario() + " se reconectó a la partida.");
            etapas->cambiarA("menu de seleccion");
        }
    } else {
        if (manager->faltanJugadores()) { // Hay espacio para un jugador más.
            Locator::logger()->log(INFO, "El usuario: " + usuario->getUsuario() + " se conectó a la partida.");
            manager->agregarUsuario(usuario);
            usuario->setValido(true);
            etapas->cambiarA("menu de seleccion");

        } else { // No queda espacio en la partida
            Locator::logger()->log(ERROR, "El usuario: " + usuario->getUsuario() + " trató de conectarse cuando la partida ya estaba completa.");
            usuario->setValido(false);
            autenticacion->partidaCompleta();
        }
    }
    usuarioAgregado.post();
}