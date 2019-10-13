//
// Created by sebas on 6/10/19.
//

#include "Transmision.h"
#include "../servicios/Locator.h"

#include <utility>
#include <sys/socket.h>

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
            socket.enviar(s);
//            int result = send(socket, msj.c_str(), msj.length(), 0);
//            if (result == -1 ){
//                Locator::logger()->log(ERROR, "Error al transmitir.");
//            } else if(result == 0){
//                Locator::logger()->log(INFO, "Cliente desconectado.");
//            } else {
//                Locator::logger()->log(DEBUG, "Transmisión correcta de: " + msj);
//            }
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
