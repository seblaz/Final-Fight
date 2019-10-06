//
// Created by sebas on 5/10/19.
//

#ifndef FINAL_FIGHT_ESCUCHA_H
#define FINAL_FIGHT_ESCUCHA_H


#include "../hilos/Eventos.h"

class Escucha {

private:
    int descriptorSocket;
    Eventos *eventos;

public:
    explicit Escucha(int descriptorSocket, Eventos *eventos);
    void escuchar();

};


#endif //FINAL_FIGHT_ESCUCHA_H
