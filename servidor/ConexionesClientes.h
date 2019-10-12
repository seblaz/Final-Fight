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

using namespace std;

class ConexionesClientes {

private:
    int socketServidor;
    ManagerUsuarios* manager;
    vector<pthread_t> hilos;
    void administrarConexionesEntrantes();
    Mapa mapa;
    void evaluarIngresoDeJugador(int nuevoSocket, bool juegoComenzado, ManagerUsuarios *pUsuarios);
    void ingresarNuevoUsuario(Usuario nuevoUsuario, Socket* pSocketNuevoUsuario, ManagerUsuarios* usuarios);

public:
    explicit ConexionesClientes(int socketServidor, ManagerUsuarios* managerUsuarios, Mapa mapa);
    ~ConexionesClientes();
    void esperarConexiones();
    vector<Socket> devolverConexiones();
    pthread_t abrirHiloConexionesEntrantes();
};


#endif //FINAL_FIGHT_CONEXIONESCLIENTES_H
