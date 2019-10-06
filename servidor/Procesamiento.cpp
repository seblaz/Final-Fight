//
// Created by sebas on 5/10/19.
//

#include "Procesamiento.h"

Eventos *Procesamiento::devolverCola() {
    return &eventos;
}

void Procesamiento::procesar() {
//    while (true) {
        auto *evento = eventos.pop();
        if (evento == nullptr) {
            printf("evento null\n");
        }
//        Hacer el broadcast.
//    }
}

pthread_t Procesamiento::procesarEnHilo() {
    pthread_t hilo;
    pthread_create(&hilo, nullptr, [](void *arg) -> void * {
        auto *procesamiento = (Procesamiento *) arg;
        procesamiento->procesar();
        return nullptr;
    }, (void *) this);
    return hilo;
}

