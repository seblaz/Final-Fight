//
// Created by sebas on 7/10/19.
//

#ifndef FINAL_FIGHT_GAMELOOP_H
#define FINAL_FIGHT_GAMELOOP_H


#include "../eventos/Eventos.h"
#include "../usuario/ManagerUsuarios.h"

class GameLoop {

private:
    EventosAProcesar* eventos;
    EventoAProcesar* eventoAProcesar;
    ManagerUsuarios* managerUsuarios;

public:
    explicit GameLoop(EventosAProcesar *eventos, EventoAProcesar *eventoAProcesar, ManagerUsuarios *managerUsuarios);
    void loop();
    pthread_t loopEnHilo();

};


#endif //FINAL_FIGHT_GAMELOOP_H
