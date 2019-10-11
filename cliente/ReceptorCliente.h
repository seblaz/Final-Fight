//
// Created by sebas on 5/10/19.
//

#ifndef FINAL_FIGHT_RECEPTORCLIENTE_H
#define FINAL_FIGHT_RECEPTORCLIENTE_H

#include <pthread.h>
#include "ActualizadorCliente.h"

class ReceptorCliente {

private:
    std::mutex mutex;
    Socket socket;
    bool nuevo = false;
    stringstream ultimoStream;
    void recibir();

public:
    explicit ReceptorCliente(Socket socket);
    void devolverStreamMasReciente(stringstream &s);
    pthread_t recibirEnHilo();
};


#endif //FINAL_FIGHT_RECEPTORCLIENTE_H
