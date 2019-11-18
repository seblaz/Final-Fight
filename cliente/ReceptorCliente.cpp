//
// Created by sebas on 5/10/19.
//

#include <sys/socket.h>
#include "ReceptorCliente.h"
#include "../servicios/Locator.h"

ReceptorCliente::ReceptorCliente() :
        disponible(0),
        finSemaforo(0) {}

void ReceptorCliente::recibir() {
    stringstream s;
    while (!fin && !Locator::socket()->estaDesconectado()) {
        s.str(std::string());
        if (!Locator::socket()->recibir(s)) {
            Locator::logger()->log(ERROR, "Se detecta desconexión del servidor.");
            Locator::socket()->finalizarConexion();
            disponible.post();
            break;
        }

        {
            std::lock_guard<std::mutex> lock(mutex);
            ultimoStream.str(s.str());
        }
        disponible.post();
    }
    finSemaforo.post();
    Locator::logger()->log(DEBUG, "Se termina el hilo del receptor.");
}

void ReceptorCliente::devolverStreamMasReciente(stringstream &s) {
    disponible.wait();
    {
        std::lock_guard<std::mutex> lock(mutex);
        s.str(ultimoStream.str());
    }
}

pthread_t ReceptorCliente::recibirEnHilo() {
    Locator::logger()->log(DEBUG, "Se creó el hilo de recepción.");
    return lanzarHilo(bind(&ReceptorCliente::recibir, this));
}

void ReceptorCliente::finalizar() {
    fin = true;
    finSemaforo.wait();
}
