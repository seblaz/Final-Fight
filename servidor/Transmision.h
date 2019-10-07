//
// Created by sebas on 6/10/19.
//

#ifndef FINAL_FIGHT_TRANSMISION_H
#define FINAL_FIGHT_TRANSMICION_H

#include <vector>
#include "../eventos/Eventos.h"

using namespace std;

class Transmision {

private:
    vector<int> sockets;
    EventosATransmitir eventosATransmitir;
    void transmitir();

public:
    explicit Transmision(vector<int> sockets);
    EventosATransmitir * devolverCola();
    pthread_t transmitirEnHilo();
};


#endif //FINAL_FIGHT_TRANSMISION_H
