//
// Created by sebas on 5/10/19.
//

#ifndef FINAL_FIGHT_CONTENEDORHILOS_H
#define FINAL_FIGHT_CONTENEDORHILOS_H


#include <pthread.h>
#include <vector>
#include "../eventos/Eventos.h"
#include "ActualizadorServidor.h"
#include "../modelo/Socket.h"

using namespace std;

class ContenedorHilos {

private:
    vector<pthread_t> hilos;

public:
    void crearHilos(vector<Socket> sockets, ActualizadorServidor *actualizador);
    void esperarFinDeHilos();
};

struct escucharClienteArgs {
    Socket socket;
    ActualizadorServidor *actualizador;
};

void *escucharCliente(void *);

struct enviarAClienteArgs {
    Socket socket;
    EventosAProcesar *eventos;
};

void *enviarACliente(void *);

#endif //FINAL_FIGHT_CONTENEDORHILOS_H
