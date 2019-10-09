//
// Created by sebas on 5/10/19.
//

#ifndef FINAL_FIGHT_RECEPTORCLIENTE_H
#define FINAL_FIGHT_RECEPTORCLIENTE_H

#include <pthread.h>
#include "ActualizadorCliente.h"

class ReceptorCliente {

private:
    Socket socket;

public:
    explicit ReceptorCliente(Socket socket);
    stringstream *escuchar();

};


#endif //FINAL_FIGHT_RECEPTORCLIENTE_H
