//
// Created by sebas on 5/10/19.
//

#include "ContenedorHilos.h"
#include "Escucha.h"
#include "../servicios/Locator.h"

void ContenedorHilos::esperarFinDeHilos() {
    for(pthread_t hilo : hilos)
        pthread_join(hilo, nullptr);
    Locator::logger()->log(DEBUG, "Todos los hilos terminaron.");
}

void ContenedorHilos::crearHilos(const vector<int> &sockets, Eventos *eventos) {
    for(int socket : sockets){
        pthread_t hilo;
        auto *args = new escucharClienteArgs({socket, eventos});
        pthread_create(&hilo, nullptr, escucharCliente, (void *) args);
        hilos.push_back(hilo);
    }
}

void *escucharCliente(void *args) {
    auto *argumentos = (escucharClienteArgs *) args;
    Escucha escucha(argumentos->socket, argumentos->eventos);
    delete argumentos;
    escucha.escuchar();
    return nullptr;
}
