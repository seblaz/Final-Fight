//
// Created by sebas on 6/10/19.
//

#ifndef FINAL_FIGHT_TRANSMISION_H
#define FINAL_FIGHT_TRANSMICION_H

#include <vector>
#include "../eventos/Eventos.h"
#include "../modelo/Socket.h"

using namespace std;

class Transmision {

private:
    vector<Socket> sockets;
    EventosATransmitir eventosATransmitir;
    void transmitir();

public:
    explicit Transmision(vector<Socket> sockets);
    EventosATransmitir * devolverCola();
    pthread_t transmitirEnHilo();
};


#endif //FINAL_FIGHT_TRANSMISION_H
