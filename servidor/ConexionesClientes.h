//
// Created by sebas on 5/10/19.
//

#ifndef FINAL_FIGHT_CONEXIONESCLIENTES_H
#define FINAL_FIGHT_CONEXIONESCLIENTES_H

#include <vector>
#include <pthread.h>
#include "../modelo/Socket.h"
#include "../usuario/ManagerUsuarios.h"

using namespace std;

class ConexionesClientes {

private:
    int socketServidor;
    const int jugadoresMax;
    ManagerUsuarios manager;
    vector<int> socketsClientes;
    vector<pthread_t> hilos;
    void rechazarProximasConexiones();

public:
    explicit ConexionesClientes(int socketServidor, ManagerUsuarios managerUsuarios);
    ~ConexionesClientes();
    void esperarConexiones();
    vector<Socket> devolverConexiones();
    pthread_t rechazarConexionesEnHilo();
};


#endif //FINAL_FIGHT_CONEXIONESCLIENTES_H
