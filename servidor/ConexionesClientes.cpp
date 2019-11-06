//
// Created by sebas on 5/10/19.
//

#include "ConexionesClientes.h"
#include "../servicios/Locator.h"
#include <string>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

ConexionesClientes::ConexionesClientes(int socketServidor, ContenedorHilos* contenedor) :
        socketServidor(socketServidor),
        contenedor(contenedor) {}

void ConexionesClientes::manejarConexiones() {
    while (true) {
        sockaddr_in newSockAddr{};
        socklen_t newSockAddrSize = sizeof(newSockAddr);
        int nuevoSocket = accept(socketServidor, (sockaddr *) &newSockAddr, &newSockAddrSize);
        if (nuevoSocket < 0) {
            Locator::logger()->log(ERROR, "Error al aceptar el pedido de conexión del cliente.");
            break;
        } else {
            auto *socket = new Socket(nuevoSocket);
            contenedor->crearHilo(socket);
        }
    }
}


pthread_t ConexionesClientes::manejarConexionesEnHilo() {
    pthread_t hilo;
    pthread_create(&hilo, nullptr, [](void *arg) -> void * {
        auto *conexiones = (ConexionesClientes *) arg;
        conexiones->manejarConexiones();
        return nullptr;
    }, (void *) this);

    Locator::logger()->log(DEBUG, "Se creó el hilo de manejo de conexiones.");
    return hilo;
}