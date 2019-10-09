//
// Created by sebas on 5/10/19.
//

#ifndef FINAL_FIGHT_PROCESAMIENTO_H
#define FINAL_FIGHT_PROCESAMIENTO_H


#include "../eventos/queue.h"
#include "../modelo/Mapa.h"
#include "../eventos/Eventos.h"

class Procesamiento {

private:
    EventosAProcesar eventosAProcesar;
    Mapa mapa;

public:
    EventosAProcesar *devolverCola();
    void procesar();
    pthread_t procesarEnHilo();
};


#endif //FINAL_FIGHT_PROCESAMIENTO_H
