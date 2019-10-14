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
    while (true) {
        EventoATransmitir *evento = eventosATransmitir.pop();
        string msj = evento->msj();

        if (msj == "fin") {
            Locator::logger()->log(DEBUG, "Se termina el socket de transmisión.");
            break;
        }

        for (Socket socket : sockets->devolverSockets()){
            stringstream s(msj);
            if(!socket.enviar(s)){
                sockets->quitar(socket);
            }
        }
    }
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

    Locator::logger()->log(DEBUG, "Se creó el hilo de transmision.");
    return hilo;
}
