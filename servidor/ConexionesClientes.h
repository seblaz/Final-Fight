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
    ListaSockets sockets;
    ContenedorHilos *contenedor;
    void manejarConexiones();
//    void administrarConexionesEntrantes();
//    void evaluarIngresoDeJugador(int nuevoSocket, bool juegoComenzado, ManagerUsuarios *pUsuarios);
//    void ingresarNuevoUsuario(Usuario nuevoUsuario, Socket* pSocketNuevoUsuario, ManagerUsuarios* usuarios);
//    pthread_t abrirHiloConexionesEntrantes();

public:
    explicit ConexionesClientes(int socketServidor, ManagerUsuarios* managerUsuarios, ContenedorHilos* contenedor);
    ~ConexionesClientes();
    pthread_t manejarConexionesEnHilo();

};

#endif //FINAL_FIGHT_CONEXIONESCLIENTES_H
