//
// Created by sebas on 5/10/19.
//

#ifndef FINAL_FIGHT_RECEPTORCLIENTE_H
#define FINAL_FIGHT_RECEPTORCLIENTE_H

#include <pthread.h>
#include "ActualizadorCliente.h"

class ReceptorCliente {

private:
    bool nuevo = false;
    Socket socket;

public:
    explicit ReceptorCliente(Socket socket);
    stringstream *escuchar();
    stringstream *devolverTransmicion();
    pthread_t recibirEnHilo();
};


#endif //FINAL_FIGHT_RECEPTORCLIENTE_H
