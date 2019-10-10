//
// Created by sebas on 5/10/19.
//

#include <sys/socket.h>
#include "ReceptorCliente.h"
#include "../servicios/Locator.h"
#include "../modelo/Entidad.h"
#include "ActualizadorCliente.h"

ReceptorCliente::ReceptorCliente(Socket socket) :
        socket(socket) {}

stringstream *ReceptorCliente::escuchar() {

    auto * s = new stringstream;
    socket.recibir(*s);
    return s;
}

stringstream *ReceptorCliente::devolverTransmicion() {
    return nullptr;
}

pthread_t ReceptorCliente::recibirEnHilo() {
    pthread_t hilo;
    pthread_create(&hilo, nullptr, [](void *arg) -> void * {
        auto *receptor = (ReceptorCliente *) arg;
        receptor.re();
        return nullptr;
    }, (void *) this);

    Locator::logger()->log(DEBUG, "Se creó el hilo de transmisión.");
    return hilo;
}
