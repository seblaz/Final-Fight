//
// Created by sebas on 5/10/19.
//

#include "ConexionesClientes.h"
#include "../servicios/Locator.h"
#include <string>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

ConexionesClientes::ConexionesClientes(Socket *socketServidor) :
        socketServidor(socketServidor) {
    Locator::provide(&clientes);
}

void ConexionesClientes::manejarConexiones() {
    while (true) {
        sockaddr_in newSockAddr{};
        socklen_t newSockAddrSize = sizeof(newSockAddr);
        int nuevoSocket = accept(socketServidor->getIntSocket(), (sockaddr *) &newSockAddr, &newSockAddrSize);
        if (nuevoSocket < 0) {
            Locator::logger()->log(ERROR, "Error al aceptar el pedido de conexión del cliente.");
            break;
        } else {
            auto *socket = new Socket(nuevoSocket);
            clientes.agregarCliente(new Cliente(socket));
        }
    }
}


pthread_t ConexionesClientes::manejarConexionesEnHilo() {
    Locator::logger()->log(DEBUG, "Se creó el hilo de manejo de conexiones.");
    return lanzarHilo(bind(&ConexionesClientes::manejarConexiones, this));
}