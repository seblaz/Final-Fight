//
// Created by sebas on 5/10/19.
//

#include <sys/socket.h>
#include "ReceptorCliente.h"
#include "../servicios/Locator.h"
#include "../modelo/Entidad.h"
#include "ActualizadorCliente.h"

ReceptorCliente::ReceptorCliente(Socket socket) :
        disponible(0),
        socket(socket) {}

void ReceptorCliente::recibir() {
    while (conexionActiva) {
        stringstream s;
        if(!socket.recibir(s)){
            Locator::logger()->log(ERROR, "Se detecta desconexión del servidor.");
            conexionActiva = false;
            break;
        }
        {
            std::lock_guard<std::mutex> lock(mutex);
            ultimoStream.str(std::string());
            ultimoStream << s.str();
            if(!nuevo){
                nuevo = true;
                disponible.post();
            }
        }
    }
}

void ReceptorCliente::devolverStreamMasReciente(stringstream &s) {
    disponible.wait();
    std::lock_guard<std::mutex> lock(mutex);
    s << ultimoStream.str();
    nuevo = false;
}

pthread_t ReceptorCliente::recibirEnHilo() {
    pthread_t hilo;
    pthread_create(&hilo, nullptr, [](void *arg) -> void * {
        auto *receptor = (ReceptorCliente *) arg;
        receptor->recibir();
        return nullptr;
    }, (void *) this);

    Locator::logger()->log(DEBUG, "Se creó el hilo de recepción.");
    return hilo;
}

bool ReceptorCliente::conexionEstaActiva(){
    return conexionActiva;
}

void ReceptorCliente::finalizar() {
    conexionActiva = false;
}
