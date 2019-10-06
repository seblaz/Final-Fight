//
// Created by sebas on 5/10/19.
//

#ifndef FINAL_FIGHT_CONTENEDORHILOS_H
#define FINAL_FIGHT_CONTENEDORHILOS_H


#include <pthread.h>
#include <vector>
#include "../hilos/Eventos.h"

using namespace std;

class ContenedorHilos {

private:
    vector<pthread_t> hilos;

public:
    void crearHilos(const vector<int>& sockets, Eventos *eventos);
    void esperarFinDeHilos();
};

struct escucharClienteArgs {
    int socket;
    Eventos *eventos;
};

void *escucharCliente(void *);

#endif //FINAL_FIGHT_CONTENEDORHILOS_H
