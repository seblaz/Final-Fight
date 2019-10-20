//
// Created by sebas on 5/10/19.
//

#include "Procesamiento.h"
#include "../servicios/Locator.h"

EventosAProcesar *Procesamiento::devolverCola() {
    return &eventosAProcesar;
}

void Procesamiento::procesar() {
    while (true) {
        auto *evento = eventosAProcesar.pop();
//        Locator::logger()->log(DEBUG, "Se procesa msj: " + evento->msj() + ".");

//        try{
            evento->resolver();
//        } catch(...){
//            Locator::logger()->log(ERROR, "Error en procesamiento, se cierra el hilo");
//            pthread_exit(nullptr);
//        }

        if (evento->msj() == "fin")
            break;
    }
}

pthread_t Procesamiento::procesarEnHilo() {
    pthread_t hilo;
    pthread_create(&hilo, nullptr, [](void *arg) -> void * {
        auto *procesamiento = (Procesamiento *) arg;
        procesamiento->procesar();
        return nullptr;
    }, (void *) this);

    Locator::logger()->log(DEBUG, "Se creó el hilo de procesamiento.");
    return hilo;
}
