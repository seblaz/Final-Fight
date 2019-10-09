//
// Created by sebas on 5/10/19.
//

#include <sys/socket.h>
#include "ReceptorCliente.h"
#include "../servicios/Locator.h"
#include "../modelo/Entidad.h"
#include "ActualizadorCliente.h"

ReceptorCliente::ReceptorCliente(Socket socket) :
        socket(socket) {}

stringstream *ReceptorCliente::escuchar() {

    auto * s = new stringstream;
    socket.recibir(*s);
    return s;
}