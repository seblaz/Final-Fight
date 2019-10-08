//
// Created by sebas on 7/10/19.
//

#ifndef FINAL_FIGHT_GAMELOOP_H
#define FINAL_FIGHT_GAMELOOP_H


#include "../eventos/Eventos.h"

class GameLoop {

private:
    EventosAProcesar* eventos;
    EventoAProcesar* eventoAProcesar;
    void loop();

public:
    explicit GameLoop(EventosAProcesar *eventos, EventoAProcesar *eventoAProcesar);
    pthread_t loopEnHilo();

};


#endif //FINAL_FIGHT_GAMELOOP_H
