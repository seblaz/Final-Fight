//
// Created by sebas on 5/10/19.
//

#ifndef FINAL_FIGHT_ESCUCHA_H
#define FINAL_FIGHT_ESCUCHA_H

#include <pthread.h>
#include "Actualizador.h"

class Escucha {

private:
    int socket;
    Actualizador *actualizador;
    void escuchar();

public:
    explicit Escucha(int socket, Actualizador *actualizador);
    pthread_t escucharEnHilo();

};


#endif //FINAL_FIGHT_ESCUCHA_H
