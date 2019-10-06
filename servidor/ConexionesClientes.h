//
// Created by sebas on 5/10/19.
//

#ifndef FINAL_FIGHT_CONEXIONESCLIENTES_H
#define FINAL_FIGHT_CONEXIONESCLIENTES_H

#include <vector>
#include <pthread.h>

using namespace std;

class ConexionesClientes {

private:
    int socketServidor;
    const int jugadoresMax;
    int jugadoresFaltantes;
    vector<int> socketsClientes;
    vector<pthread_t> hilos;
    void rechazarProximasConexiones();

public:
    explicit ConexionesClientes(int socketServidor, int jugadoresMax = 4);
    ~ConexionesClientes();
    void esperarConexiones();
    vector<int> devolverConexiones();
    void rechazarConexionesEnHilo();
};


#endif //FINAL_FIGHT_CONEXIONESCLIENTES_H
