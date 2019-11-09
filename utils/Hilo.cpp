//
// Created by sebas on 5/11/19.
//

#include <pthread.h>

#include <utility>
#include "Hilo.h"
#include "../servicios/Locator.h"

Hilo::Hilo() : hiloLanzado(0) {};

pthread_t Hilo::lanzarHilo(function<void()> func) {
    funcionAux = std::move(func);
    pthread_t hilo;
    pthread_create(&hilo, nullptr, [](void *arg) -> void * {
        auto *transmision = (Hilo *) arg;
        function<void()> funcionHilo = transmision->funcionAux;
        transmision->hiloLanzado.post();
        try {
            funcionHilo();
        } catch (const std::exception &e) {
            Locator::logger()->log(ERROR, "Ocurrió una excepción: " + string(e.what()) + ".");
            exit(0);
        } catch (...) {
            Locator::logger()->log(ERROR, "Ocurrió una excepción y se debió finalizar el programa.");
            exit(0);
        }
        return nullptr;
    }, (void *) this);

    hiloLanzado.wait();
    return hilo;
}
