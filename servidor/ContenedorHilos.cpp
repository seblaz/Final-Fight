//
// Created by sebas on 5/10/19.
//

#include "ContenedorHilos.h"
#include "Escucha.h"
#include "../servicios/Locator.h"

void ContenedorHilos::esperarFinDeHilos() {
    for(pthread_t hilo : hilos)
        pthread_join(hilo, nullptr);
    Locator::logger()->log(DEBUG, "Todos los eventos terminaron.");
}

void ContenedorHilos::crearHilos(const vector<int> &sockets, EventosAProcesar *eventos) {
    for(int socket : sockets){
        pthread_t hilo;
        auto *argsEscuchar = new escucharClienteArgs({socket, eventos});
        pthread_create(&hilo, nullptr, escucharCliente, (void *) argsEscuchar);
        hilos.push_back(hilo);

//        auto *argsEnviar = new enviarAClienteArgs({socket, eventos});
//        pthread_create(&hilo, nullptr, enviarACliente, (void *) argsEnviar);

    }
}

void *escucharCliente(void *args) {
    auto *argumentos = (escucharClienteArgs *) args;
    Escucha escucha(argumentos->socket, argumentos->eventos);
    delete argumentos;
    escucha.escuchar();
    return nullptr;
}

void *enviarACliente(void *args) {
    auto *argumentos = (enviarAClienteArgs *) args;
    Escucha escucha(argumentos->socket, argumentos->eventos);
    delete argumentos;
    escucha.escuchar();
    return nullptr;
}
