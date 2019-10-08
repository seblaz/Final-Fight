//
// Created by sebas on 5/10/19.
//

#include <cstring>
#include "Escucha.h"
#include "../servicios/Locator.h"
#include "../eventos/data.h"
#include "../modelo/Accion.h"
#include <sys/socket.h>

Escucha::Escucha(int descriptorSocket) :
        descriptorSocket(descriptorSocket) {}

void Escucha::escuchar(ActualizadorServidor *actualizador) {

    stringstream s;
    char msg[5000];

    while (true) {
        memset(&msg, 0, sizeof(msg)); // clear the buffer

        int valueRead = recv(descriptorSocket, (char *) &msg, sizeof(msg), 0);
        if (valueRead < 0) {
            Locator::logger()->log(ERROR, string("No se pudo leer datos del cliente. Error: ").append(strerror(errno)) + ". Se termina el hilo.");
            break;
        } else if(valueRead == 0){
            Locator::logger()->log(INFO, "El cliente se desconectó.");
            break;
        } else {
            Locator::logger()->log(DEBUG, string("Se recibe msj: ").append(msg) + ".");
            s << msg;
            actualizador->interpretarComando(s);
        }
    }

}

