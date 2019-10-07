//
// Created by sebas on 5/10/19.
//

#ifndef FINAL_FIGHT_ESCUCHA_H
#define FINAL_FIGHT_ESCUCHA_H


#include "../eventos/Eventos.h"

class Escucha {

private:
    int descriptorSocket;
    EventosAProcesar *eventos;

public:
    explicit Escucha(int descriptorSocket, EventosAProcesar *eventos);
    void escuchar();

};


#endif //FINAL_FIGHT_ESCUCHA_H
