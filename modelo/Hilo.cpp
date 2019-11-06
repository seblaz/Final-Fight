//
// Created by sebas on 5/11/19.
//

#include <pthread.h>

#include <utility>
#include "Hilo.h"
#include "../servicios/Locator.h"


pthread_t Hilo::lanzarHilo(function<void()> func) {
    funcionAux = std::move(func);
    pthread_t hilo;
    pthread_create(&hilo, nullptr, [](void *arg) -> void * {
        auto *transmision = (Hilo *) arg;
        function<void()> funcionHilo = transmision->funcionAux;
        transmision->hiloLanzado.post();
        funcionHilo();
        return nullptr;
    }, (void *) this);

    hiloLanzado.wait();
    Locator::logger()->log(DEBUG, "Se creó el hilo de transmisión.");
    return hilo;
}
