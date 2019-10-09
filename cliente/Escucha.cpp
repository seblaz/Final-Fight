//
// Created by sebas on 5/10/19.
//

#include <sys/socket.h>
#include "Escucha.h"
#include "../servicios/Locator.h"
#include "../modelo/Entidad.h"
#include "ActualizadorCliente.h"

Escucha::Escucha(int socket) :
        socket(socket),
        actualizador(actualizador) {}

void Escucha::escuchar() {

    stringstream s;
    char msg[5000];

    while (true) {
        memset(&msg, 0, sizeof(msg)); // clear the buffer

        int valueRead = recv(socket, (char *) &msg, sizeof(msg), 0);
        if (valueRead < 0) {
            Locator::logger()->log(ERROR, string("No se pudo leer datos del cliente. Error: ").append(strerror(errno)) + ". Se termina el hilo.");
            break;
        } else if(valueRead == 0){
            Locator::logger()->log(INFO, "El cliente se desconectó.");
            break;
        } else {
//            Locator::logger()->log(DEBUG, string("Se recibe msj: ").append(msg) + ".");
            s << msg;
            actualizador->actualizarEntidades(s);
        }
    }

}

pthread_t Escucha::escucharEnHilo() {
    pthread_t hilo;
    pthread_create(&hilo, nullptr, [](void *arg) -> void * {
        auto *escucha = (Escucha *) arg;
        escucha->escuchar();
        return nullptr;
    }, (void *) this);

    Locator::logger()->log(DEBUG, "Se creó el hilo que escucha las actualizaciones del servidor.");

    return hilo;
}
