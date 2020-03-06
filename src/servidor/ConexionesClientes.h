//
// Created by sebas on 5/10/19.
//

#ifndef FINAL_FIGHT_CONEXIONESCLIENTES_H
#define FINAL_FIGHT_CONEXIONESCLIENTES_H

#include <vector>
#include <pthread.h>
#include "../utils/Socket.h"
#include "../usuario/ManagerUsuarios.h"
#include "../modelo/Mapa.h"
#include "../utils/Hilo.h"
#include "clientes/ManagerClientes.h"

class ConexionesClientes : public Hilo {

private:
    Socket *socketServidor;
    ManagerClientes clientes;
    void manejarConexiones();

public:
    explicit ConexionesClientes(Socket *socketServidor);
    pthread_t manejarConexionesEnHilo();

};

#endif //FINAL_FIGHT_CONEXIONESCLIENTES_H
