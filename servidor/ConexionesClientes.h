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

class ConexionesClientes {

private:
    int socketServidor;
    ContenedorHilos *contenedor;
    void manejarConexiones();

public:
    ConexionesClientes(int socketServidor, ContenedorHilos* contenedor);
    pthread_t manejarConexionesEnHilo();

};

#endif //FINAL_FIGHT_CONEXIONESCLIENTES_H
