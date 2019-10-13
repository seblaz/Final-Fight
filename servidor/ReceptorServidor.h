//
// Created by sebas on 5/10/19.
//

#ifndef FINAL_FIGHT_RECEPTORSERVIDOR_H
#define FINAL_FIGHT_RECEPTORSERVIDOR_H


#include "../eventos/Eventos.h"
#include "actualizadores/ActualizadorJuego.h"
#include "../modelo/Socket.h"
#include "actualizadores/Actualizador.h"
#include "../usuario/ManagerUsuarios.h"

class ReceptorServidor {

private:
    Mapa *mapa;
    Socket socket;
    ManagerUsuarios *manager;
    EventosAProcesar *eventos;

public:
    ReceptorServidor(Mapa *mapa, Socket socket, ManagerUsuarios *manager, EventosAProcesar *eventos);
    void recibir();

};


#endif //FINAL_FIGHT_RECEPTORSERVIDOR_H
