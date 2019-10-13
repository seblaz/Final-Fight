///
// Created by sebas on 5/10/19.
//

#include "ContenedorHilos.h"
#include "ReceptorServidor.h"
#include "../servicios/Locator.h"

ContenedorHilos::ContenedorHilos(Mapa *mapa, EventosAProcesar *eventosAProcesar, ManagerUsuarios *manager) :
        mapa(mapa),
        manager(manager),
        eventosAProcesar(eventosAProcesar) {}

void ContenedorHilos::esperarFinDeHilos() {
    for (pthread_t hilo : hilos)
        pthread_join(hilo, nullptr);
    Locator::logger()->log(DEBUG, "Todos los eventos terminaron.");
}

void ContenedorHilos::crearHilo(Socket socket) {
    Locator::logger()->log(DEBUG, "Se crea un nuevo thread para recibir las acciones de los clientes.");

    pthread_t hilo;
    auto *argsEscuchar = new escucharClienteArgs({mapa, socket, manager, eventosAProcesar});
    pthread_create(&hilo, nullptr, escucharCliente, (void *) argsEscuchar);
    hilos.push_back(hilo);
}

void *escucharCliente(void *args) {
    auto *argumentos = (escucharClienteArgs *) args;
    ReceptorServidor receptor(argumentos->mapa, argumentos->socket, argumentos->manager, argumentos->eventos);
    delete argumentos;
    receptor.recibir();
    return nullptr;
}