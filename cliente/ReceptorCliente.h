//
// Created by sebas on 5/10/19.
//

#ifndef FINAL_FIGHT_RECEPTORCLIENTE_H
#define FINAL_FIGHT_RECEPTORCLIENTE_H

#include <pthread.h>
#include <mutex>
#include <sstream>
#include "../eventos/semaphore.h"

using namespace std;

class ReceptorCliente {

private:
    std::mutex mutex;
    bool nuevo = false;
    semaphore disponible;
    stringstream ultimoStream;
    void recibir();

public:
    ReceptorCliente();
    void devolverStreamMasReciente(stringstream &s);
    pthread_t recibirEnHilo();

};


#endif //FINAL_FIGHT_RECEPTORCLIENTE_H
