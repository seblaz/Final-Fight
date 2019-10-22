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
    semaphore disponible;
    stringstream ultimoStream;
    void recibir();
    bool conexionActiva = true;

public:
    explicit ReceptorCliente(Socket socket);
    void devolverStreamMasReciente(stringstream &s);
    pthread_t recibirEnHilo();
    bool conexionEstaActiva();

    void finalizar();

    static clock_t ultimaRecepcion;
};


#endif //FINAL_FIGHT_RECEPTORCLIENTE_H
