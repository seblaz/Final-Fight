//
// Created by sebas on 5/10/19.
//

#ifndef FINAL_FIGHT_CONEXIONESCLIENTES_H
#define FINAL_FIGHT_CONEXIONESCLIENTES_H

#include <vector>
#include <pthread.h>
#include "../modelo/Socket.h"
#include "../usuario/ManagerUsuarios.h"
#include "../modelo/Mapa.h"
#include "ContenedorHilos.h"
#include "ListaSockets.h"

class ConexionesClientes {

private:
    int socketServidor;
    ManagerUsuarios* manager;
    ListaSockets *sockets;
    ContenedorHilos *contenedor;
    void manejarConexiones();

public:
    explicit ConexionesClientes(int socketServidor, ListaSockets *sockets, ManagerUsuarios* managerUsuarios, ContenedorHilos* contenedor);
    pthread_t manejarConexionesEnHilo();

};

#endif //FINAL_FIGHT_CONEXIONESCLIENTES_H
