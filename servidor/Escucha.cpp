//
// Created by sebas on 5/10/19.
//

#include <cstring>
#include "Escucha.h"
#include "../servicios/Locator.h"
#include "../eventos/data.h"
#include <sys/socket.h>

Escucha::Escucha(int descriptorSocket, EventosAProcesar *eventos) :
        eventos(eventos),
        descriptorSocket(descriptorSocket) {}

void Escucha::escuchar() {

    while(true) {
        char msg[1500];
        memset(&msg, 0, sizeof(msg)); // clear the buffer

        miData var{};

        int valueRead = recv(descriptorSocket, &var, sizeof(var), 0);
        if (valueRead <= 0) {
            Locator::logger()->log(ERROR, string("No se pudo leer datos del cliente. Error: ").append(strerror(errno)) + ". Se termina el hilo.");
            break;
        } else {
            auto *evento = new EventoAProcesar(msg);
//            Locator::logger()->log(DEBUG, string("Se recibe msj_: ").append(msj_) + ".");
            Locator::logger()->log(DEBUG, to_string(var.x) + to_string(var.y));
            eventos->push(evento);
        }
    }

}

