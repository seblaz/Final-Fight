//
// Created by sebas on 5/10/19.
//

#include "ReceptorServidor.h"
#include "../usuario/Usuario.h"
#include "actualizadores/ActualizadorUsuario.h"
#include "actualizadores/ActualizadorMenuSeleccion.h"
#include "../modelo/Actividad.h"


semaphore *ReceptorServidor::confirmacion = new semaphore(0);

ReceptorServidor::ReceptorServidor(Mapa *mapa, Socket *socket, ListaSockets *listaSockets, ManagerUsuarios *manager,
                                   EventosAProcesar *eventos, SelectorPersonajes *selector) :
        mapa(mapa),
        socket(socket),
        manager(manager),
        eventos(eventos),
        selector(selector),
        listaSockets(listaSockets) {}

void ReceptorServidor::recibir() {
    // Validar usuario.
    ActualizadorUsuario actualizadorUsuario(eventos, manager);
    Usuario *usuario = actualizadorUsuario.getUsuario(socket);
    listaSockets->agregar(socket);

    if (!usuario->getPersonaje()) {
        // Menu se seleccion de personaje.
        ActualizadorMenuSeleccion actualizadorMenu(mapa, eventos, selector, usuario, manager, confirmacion);
        actualizadorMenu.actualizarPersonaje();
    }

    // Activar el jugador por si fue desconectado.
    Entidad *jugador = usuario->getPersonaje();
    eventos->push(new SetActividadJugador(jugador, true));

    // Actualizar el juego.
    ActualizadorJuego actualizadorJuego(mapa, eventos, jugador, manager);
    actualizadorJuego.actualizarJuego(usuario);
}