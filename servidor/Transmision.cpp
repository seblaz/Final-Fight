//
// Created by sebas on 6/10/19.
//

#include "Transmision.h"
#include "../servicios/Locator.h"

#include <utility>
#include <sys/socket.h>
#include <csignal>

Transmision::Transmision(ListaSockets *sockets) :
        sockets(sockets) {}

void Transmision::transmitir() {
    while (!fin) {
        EventoATransmitir *evento = eventosATransmitir.pop();
        string msj = evento->msj();

        for (Socket *socket : sockets->devolverSockets()) {
            stringstream s(msj);
            if (socket->estaDesconectado() || !socket->enviar(s)) {
                Locator::logger()->log(ERROR, "Se detecta socket invalido, se quita de la lista de sockets y se cierra.");
                sockets->quitar(socket);
            }
        }
    }
    Locator::logger()->log(DEBUG, "Se termina el hilo de transmisión.");
}

EventosATransmitir *Transmision::devolverCola() {
    return &eventosATransmitir;
}

pthread_t Transmision::transmitirEnHilo() {
    pthread_t hilo;
    pthread_create(&hilo, nullptr, [](void *arg) -> void * {
        auto *transmision = (Transmision *) arg;
        transmision->transmitir();
        return nullptr;
    }, (void *) this);

    Locator::logger()->log(DEBUG, "Se creó el hilo de transmisión.");
    return hilo;
}

void Transmision::finalizar() {
    fin = true;
    eventosATransmitir.push(new EventoATransmitir());
}
