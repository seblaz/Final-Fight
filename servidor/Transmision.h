//
// Created by sebas on 6/10/19.
//

#ifndef FINAL_FIGHT_TRANSMISION_H
#define FINAL_FIGHT_TRANSMICION_H

#include <vector>
#include "../eventos/Eventos.h"
#include "../modelo/Socket.h"
#include "ListaSockets.h"

using namespace std;

class Transmision {

private:
    ListaSockets *sockets;
    EventosATransmitir eventosATransmitir;
    void transmitir();

public:
    explicit Transmision(ListaSockets *sockets);
    EventosATransmitir * devolverCola();
    pthread_t transmitirEnHilo();
};


#endif //FINAL_FIGHT_TRANSMISION_H
