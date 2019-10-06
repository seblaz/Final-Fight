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
    char msg[1500];
    memset(&msg, 0, sizeof(msg)); // clear the buffer

    int valueRead = recv(descriptorSocket, (char *) &msg, sizeof(msg), 0);
    if (valueRead <= 0) {
        Locator::logger()->log(ERROR, string("No se pudo leer información del cliente. Error: ").append(strerror(errno)) + ".");
    } else {
        printf("%s\n", msg);
    }
}

