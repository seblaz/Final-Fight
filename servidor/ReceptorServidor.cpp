//
// Created by sebas on 5/10/19.
//

#include "ReceptorServidor.h"
#include "../usuario/Usuario.h"
#include "actualizadores/ActualizadorUsuario.h"
#include "actualizadores/ActualizadorMenuSeleccion.h"
#include "NivelServidor.h"


ReceptorServidor::ReceptorServidor(Mapa *mapa, Socket socket, ManagerUsuarios *manager, EventosAProcesar *eventos,
                                   SelectorPersonajes *selector, semaphore *confirmacion) :
        mapa(mapa),
        socket(socket),
        manager(manager),
        eventos(eventos),
        selector(selector),
        confirmacion(confirmacion) {}

void ReceptorServidor::recibir() {

    ActualizadorUsuario actualizadorUsuario(eventos, manager);
    Locator::logger()->log(DEBUG, "Se crea un actualizador de usuario.");

//    do {
    stringstream s;
    if (!socket.recibir(s)) {
        Locator::logger()->log(ERROR, "Se termina el hilo.");
        pthread_exit(nullptr);
    }
    Usuario *usuario = actualizadorUsuario.interpretarStream(s, socket);
//    } while (!actualizadorUsuario.fin());

    if (!usuario->getPersonaje()) {
        ActualizadorMenuSeleccion actualizadorMenu(mapa, eventos, selector, usuario, manager, confirmacion);
        Locator::logger()->log(DEBUG, "Se crea un actualizador de menu de selección.");
        do {
            stringstream ss;
            if (!socket.recibir(ss)) {
                Locator::logger()->log(ERROR, "Se termina el hilo.");
                pthread_exit(nullptr);
            }
            actualizadorMenu.interpretarStream(ss);
        } while (!actualizadorMenu.fin());

        confirmacion->wait();
    }
    Entidad *jugador = usuario->getPersonaje();
    
    ActualizadorJuego actualizadorJuego(mapa, eventos, jugador);
    Locator::logger()->log(DEBUG, "Se crea un actualizador de juego.");
    do {
        stringstream sss;
        if (!socket.recibir(sss)) {
            usuario->setSocket(nullptr);
            usuario->desactivar();
            Locator::logger()->log(ERROR, "Se termina el hilo.");
            pthread_exit(nullptr);
        }
        actualizadorJuego.interpretarStream(sss);
    } while (!actualizadorJuego.fin());
}
