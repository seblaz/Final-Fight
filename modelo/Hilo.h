//
// Created by sebas on 5/11/19.
//

#ifndef FINAL_FIGHT_HILO_H
#define FINAL_FIGHT_HILO_H

#include <sys/socket.h>
#include "../eventos/semaphore.h"
#include <functional>

using namespace std;

class Hilo {

protected:
    function<void()> funcionAux;
    semaphore hiloLanzado;

public:
    Hilo();
    pthread_t lanzarHilo(function<void()> fun);

};


#endif //FINAL_FIGHT_HILO_H
