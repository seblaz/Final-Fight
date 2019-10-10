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

void ReceptorCliente::recibir() {
    while (true) {
        stringstream s;
        socket.recibir(s);
        {
            std::lock_guard<std::mutex> lock(mutex);
            ultimoStream.str(std::string());
            ultimoStream << s.str();
        }
    }
}

void ReceptorCliente::devolverStreamMasReciente(stringstream &s) {
    std::lock_guard<std::mutex> lock(mutex);
    s << ultimoStream.str();
}

pthread_t ReceptorCliente::recibirEnHilo() {
    pthread_t hilo;
    pthread_create(&hilo, nullptr, [](void *arg) -> void * {
        auto *receptor = (ReceptorCliente *) arg;
        receptor->recibir();
        return nullptr;
    }, (void *) this);

    Locator::logger()->log(DEBUG, "Se creó el hilo de transmisión.");
    return hilo;
}
