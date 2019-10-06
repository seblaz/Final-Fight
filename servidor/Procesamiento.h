//
// Created by sebas on 5/10/19.
//

#ifndef FINAL_FIGHT_PROCESAMIENTO_H
#define FINAL_FIGHT_PROCESAMIENTO_H


#include "../hilos/Eventos.h"
#include "../hilos/Evento.h"

class Procesamiento {

private:
    Eventos eventos;

public:
    Eventos *devolverCola();
    void procesar();
    pthread_t procesarEnHilo();
};


#endif //FINAL_FIGHT_PROCESAMIENTO_H
