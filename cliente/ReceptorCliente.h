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
    bool nuevo = false;
    semaphore disponible;
    stringstream ultimoStream;
    void recibir();
    bool conexionActiva = true;

public:
    ReceptorCliente();
    void devolverStreamMasReciente(stringstream &s);
    pthread_t recibirEnHilo();
    bool conexionEstaActiva();

    void finalizar();

    static std::chrono::time_point<std::chrono::system_clock> ultimaRecepcion;
};


#endif //FINAL_FIGHT_RECEPTORCLIENTE_H
