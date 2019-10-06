//
// Created by sebas on 5/10/19.
//

#include <cstring>
#include "Escucha.h"
#include "../servicios/Locator.h"
#include "../hilos/Eventos.h"
#include <sys/socket.h>

Escucha::Escucha(int descriptorSocket, Eventos *eventos) :
        eventos(eventos),
        descriptorSocket(descriptorSocket) {}

void Escucha::escuchar() {

    while(true) {
        char msg[1500];
        memset(&msg, 0, sizeof(msg)); // clear the buffer

        int valueRead = recv(descriptorSocket, (char *) &msg, sizeof(msg), 0);
        if (valueRead <= 0) {
            Locator::logger()->log(ERROR, string("No se pudo leer datos del cliente. Error: ").append(strerror(errno)) + ". Se termina el hilo.");
            break;
        } else {
            auto *evento = new Evento(msg);
            Locator::logger()->log(DEBUG, string("Se recibe msg: ").append(msg) + ".");
            eventos->push(evento);
        }
    }

}

