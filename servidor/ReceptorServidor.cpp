//
// Created by sebas on 5/10/19.
//

#include "ReceptorServidor.h"
#include "../usuario/Usuario.h"
#include "etapas/EtapaUsuario.h"
#include "etapas/ManagerEtapas.h"
#include "../servicios/Locator.h"

ReceptorServidor::ReceptorServidor(Mapa *mapa, Socket *socket, ListaSockets *listaSockets, ManagerUsuarios *manager,
                                   EventosAProcesar *eventos, SelectorPersonajes *selector) :
        mapa(mapa),
        socket(socket),
        manager(manager),
        eventos(eventos),
        selector(selector),
        listaSockets(listaSockets) {}

void ReceptorServidor::recibir() {
    ManagerEtapas managerEtapas;
    managerEtapas.agregar(new EtapaUsuario("validar usuario", socket, manager));

    stringstream s;
    do{
        if (!socket->recibir(s)) {
            Locator::logger()->log(ERROR, "Se desconectó el cliente de forma inesperada.");
            break;
        }
    } while (managerEtapas.getActual()->actualizar(s));

    Locator::logger()->log(INFO, "Se termina el hilo.");
    managerEtapas.getActual()->finalizar();

    // Validar usuario.
//    ActualizadorUsuario actualizadorUsuario(eventos, manager);
//    Usuario *usuario = actualizadorUsuario.getUsuario(socket);
//    listaSockets->agregar(socket);
//
//    if (!usuario->getPersonaje()) {
//        // Menu se seleccion de personaje.
//        ActualizadorMenuSeleccion actualizadorMenu(mapa, eventos, selector, usuario, manager, confirmacion);
//        actualizadorMenu.actualizarPersonaje();
//    }
//
//    // Activar el jugador por si fue desconectado.
//    Entidad *jugador = usuario->getPersonaje();
//    eventos->push(new SetActividadJugador(jugador, true));
//
//    // Actualizar el juego.
//    ActualizadorJuego actualizadorJuego(mapa, eventos, jugador, manager);
//    actualizadorJuego.actualizarJuego(usuario);
}