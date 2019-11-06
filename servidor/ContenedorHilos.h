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
#include "clientes/Cliente.h"
#include "clientes/ManagerClientes.h"

using namespace std;

class ContenedorHilos {

private:
    vector<pthread_t> hilos;
    ManagerClientes clientes;

public:
    ContenedorHilos();
    void crearHilo(Socket *socket);
    void esperarFinDeHilos();
};

#endif //FINAL_FIGHT_CONTENEDORHILOS_H
