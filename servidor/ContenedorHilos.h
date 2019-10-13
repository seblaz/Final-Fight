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

using namespace std;

class ContenedorHilos {

private:
    vector<pthread_t> hilos;
    Mapa *mapa;
    ManagerUsuarios *manager;
    EventosAProcesar *eventosAProcesar;

public:
    ContenedorHilos(Mapa *mapa, EventosAProcesar *eventosAProcesar, ManagerUsuarios *manager);
    void crearHilo(Socket socket);
    void esperarFinDeHilos();
};

struct escucharClienteArgs {
    Mapa *mapa{};
    Socket socket;
    ManagerUsuarios *manager{};
    EventosAProcesar *eventos{};
};

void *escucharCliente(void *);

#endif //FINAL_FIGHT_CONTENEDORHILOS_H
