//
// Created by sebas on 5/10/19.
//

#ifndef FINAL_FIGHT_ESCUCHA_H
#define FINAL_FIGHT_ESCUCHA_H


#include "../eventos/Eventos.h"
#include "ActualizadorServidor.h"
#include "../modelo/Socket.h"

class Escucha {

private:
    Socket socket;

public:
    explicit Escucha(Socket socket);
    void escuchar(ActualizadorServidor *actualizador);

};


#endif //FINAL_FIGHT_ESCUCHA_H
