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
    bool fin = false;

public:
    EventosAProcesar *devolverCola();
    void procesar();
    void finalizar();
    pthread_t procesarEnHilo();
};

class EventoVacio : public EventoAProcesar {

public:
    void resolver() override {};

};

#endif //FINAL_FIGHT_PROCESAMIENTO_H
