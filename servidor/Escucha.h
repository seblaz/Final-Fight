//
// Created by sebas on 5/10/19.
//

#ifndef FINAL_FIGHT_ESCUCHA_H
#define FINAL_FIGHT_ESCUCHA_H


#include "../eventos/Eventos.h"
#include "ActualizadorServidor.h"

class Escucha {

private:
    int descriptorSocket;

public:
    explicit Escucha(int descriptorSocket);
    void escuchar(ActualizadorServidor *actualizador);

};


#endif //FINAL_FIGHT_ESCUCHA_H
