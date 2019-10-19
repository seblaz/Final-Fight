//
// Created by sebas on 5/10/19.
//

#ifndef FINAL_FIGHT_RECEPTORSERVIDOR_H
#define FINAL_FIGHT_RECEPTORSERVIDOR_H


#include "../eventos/Eventos.h"
#include "actualizadores/ActualizadorJuego.h"
#include "../modelo/Socket.h"
#include "../usuario/ManagerUsuarios.h"
#include "SelectorPersonajes.h"
#include "ListaSockets.h"

class ReceptorServidor {

private:
    Mapa *mapa;
    Socket socket;
    ManagerUsuarios *manager;
    EventosAProcesar *eventos;
    SelectorPersonajes *selector;
    ListaSockets *listaSockets;
    static semaphore *confirmacion;

public:
    ReceptorServidor(Mapa *mapa, Socket socket, ListaSockets *listaSockets, ManagerUsuarios *manager,
                     EventosAProcesar *eventos, SelectorPersonajes *selector);
    void recibir();

};

#endif //FINAL_FIGHT_RECEPTORSERVIDOR_H
