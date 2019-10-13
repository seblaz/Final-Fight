//
// Created by sebas on 5/10/19.
//

#include "ReceptorServidor.h"
#include "../usuario/Usuario.h"
#include "actualizadores/ActualizadorUsuario.h"
#include "actualizadores/ActualizadorMenuSeleccion.h"


ReceptorServidor::ReceptorServidor(Mapa *mapa, Socket socket, ManagerUsuarios * manager, EventosAProcesar *eventos) :
        mapa(mapa),
        socket(socket),
        manager(manager),
        eventos(eventos) {}
        
void ReceptorServidor::recibir() {

    ActualizadorUsuario actualizadorUsuario(manager);
    Locator::logger()->log(DEBUG, "Se crea un actualizador de usuario.");
    
    do {
        stringstream s;
        if (!socket.recibir(s)) pthread_exit(nullptr);
        actualizadorUsuario.interpretarStream(s);
    } while (!actualizadorUsuario.fin());

    ActualizadorMenuSeleccion actualizadorMenu(mapa, eventos);
    Locator::logger()->log(DEBUG, "Se crea un actualizador de menu de selección.");
    do {
        stringstream s;
        if (!socket.recibir(s)) pthread_exit(nullptr);
        actualizadorMenu.interpretarStream(s);
    } while (!actualizadorMenu.fin());

    ActualizadorJuego actualizadorJuego(mapa, eventos);
    Locator::logger()->log(DEBUG, "Se crea un actualizador de juego.");
    do {
        stringstream s;
        if (!socket.recibir(s)) pthread_exit(nullptr);
        actualizadorMenu.interpretarStream(s);
    } while (!actualizadorJuego.fin());
}
