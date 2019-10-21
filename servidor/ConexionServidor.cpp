//
// Created by sebas on 4/10/19.
//

#include "ConexionServidor.h"
#include "../servicios/Locator.h"

ConexionServidor::ConexionServidor(int puerto) {
    sockaddr_in serverAddr{};
    bzero((char *) &serverAddr, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serverAddr.sin_port = htons(puerto);

    descriptorSocket = ::socket(AF_INET, SOCK_STREAM, 0);
    if (descriptorSocket < 0) {
        Locator::logger()->log(ERROR, "No se pudo crear el socket para aceptar clientes en el servidor. Se termina el programa.");
        exit(0);
    }

    int bindStatus = bind(descriptorSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr));
    if (bindStatus < 0) {
        Locator::logger()->log(ERROR, string("No se pudo realizar el binding en el socket del servidor. Error: ").append(strerror(errno)) + ". Se termina el programa.");
        exit(0);
    }

    listen(descriptorSocket, 4); // listen for up to 4 requests at a time
    Locator::logger()->log(DEBUG, "Se creó el socket de aceptación.");
}

ConexionServidor::~ConexionServidor() {
//    close(descriptorSocket);
//    Locator::logger()->log(DEBUG, "Se cerró el socket de aceptación.");
}

int ConexionServidor::socket() {
    return descriptorSocket;
}
