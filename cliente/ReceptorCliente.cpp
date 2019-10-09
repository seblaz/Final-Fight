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
//    char msg[5000];
//    memset(&msg, 0, sizeof(msg)); // clear the buffer
//    int valueRead = recv(socket, (char *) &msg, sizeof(msg), 0);
//    if (valueRead < 0) {
//        Locator::logger()->log(ERROR, string("No se pudo leer datos del cliente. Error: ").append(strerror(errno)) + ". Se termina el hilo.");
//    } else if (valueRead == 0) {
//        Locator::logger()->log(INFO, "El cliente se desconectó.");
//    } else {
//        Locator::logger()->log(INFO, string("Se recibe: ").append(msg));
//        *s << msg;
//        return s;
//    }
    return s;
}