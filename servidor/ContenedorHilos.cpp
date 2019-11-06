///
// Created by sebas on 5/10/19.
//

#include "ContenedorHilos.h"
#include "../servicios/Locator.h"


void ContenedorHilos::esperarFinDeHilos() {
    for (pthread_t hilo : hilos)
        pthread_join(hilo, nullptr);
    Locator::logger()->log(DEBUG, "Todos los hilos de los clientes terminaron.");
}

void ContenedorHilos::crearHilo(Socket *socket) {
    Locator::logger()->log(DEBUG, "Se crea un nuevo thread para recibir las acciones de los clientes.");

//    pthread_t hilo;
//    auto *argsEscuchar = new escucharClienteArgs({mapa, socket, listaSockets, manager, eventosAProcesar, selector});
//    pthread_create(&hilo, nullptr, escucharCliente, (void *) argsEscuchar);
//    hilos.push_back(hilo);
    auto *cliente = new Cliente(socket);
    clientes.push_back(cliente);

}

//void *escucharCliente(void *args) {
//    auto *argumentos = (escucharClienteArgs *) args;
//    ReceptorServidor receptor(argumentos->mapa, argumentos->socket, argumentos->listaSockets,
//                              argumentos->manager, argumentos->eventos,
//                              argumentos->selector);
//    delete argumentos;
//    receptor.recibir();
//    Locator::logger()->log(INFO, "Se termina un hilo de cliente");
//    return nullptr;
//}