//
// Created by sebas on 5/10/19.
//

#ifndef FINAL_FIGHT_ESCUCHA_H
#define FINAL_FIGHT_ESCUCHA_H

#include <pthread.h>
#include "ActualizadorCliente.h"

class Escucha {

private:
    int socket;
    ActualizadorCliente *actualizador;
    void escuchar();

public:
    explicit Escucha(int socket);

};


#endif //FINAL_FIGHT_ESCUCHA_H
