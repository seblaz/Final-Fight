//
// Created by sebas on 5/10/19.
//

#ifndef FINAL_FIGHT_CONTENEDORHILOS_H
#define FINAL_FIGHT_CONTENEDORHILOS_H


#include <pthread.h>
#include <vector>
#include "../eventos/Eventos.h"
#include "../modelo/Socket.h"
#include "../usuario/ManagerUsuarios.h"
#include "SelectorPersonajes.h"
#include "ListaSockets.h"

using namespace std;

class ContenedorHilos {

private:
    vector<pthread_t> hilos;
    Mapa *mapa;
    ManagerUsuarios *manager;
    EventosAProcesar *eventosAProcesar;
    SelectorPersonajes *selector;
    ListaSockets *listaSockets;
    semaphore confirmacion;

public:
    ContenedorHilos(Mapa *mapa, EventosAProcesar *eventosAProcesar, ManagerUsuarios *manager,
                    SelectorPersonajes *selector, ListaSockets *listaSockets);
    void crearHilo(Socket socket);
    void esperarFinDeHilos();
};

struct escucharClienteArgs {
    Mapa *mapa{};
    Socket socket;
    ListaSockets *listaSockets{};
    ManagerUsuarios *manager{};
    EventosAProcesar *eventos{};
    SelectorPersonajes *selector{};
    semaphore *confirmacion{};
};

void *escucharCliente(void *);

#endif //FINAL_FIGHT_CONTENEDORHILOS_H
