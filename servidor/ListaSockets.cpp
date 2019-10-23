//
// Created by sebas on 12/10/19.
//

#include "ListaSockets.h"
#include "../servicios/Locator.h"
#include <algorithm>
#include <unistd.h>
#include <sys/socket.h>

void ListaSockets::agregar(Socket *socket) {
    lock_guard<mutex> lock(m);
    sockets.push_back(socket);
}

vector<Socket *> ListaSockets::devolverSockets() {
    lock_guard<mutex> lock(m);
    return vector<Socket *>(sockets);
}

void ListaSockets::quitar(Socket *socket) {
    lock_guard<mutex> lock(m);
    auto position = find(sockets.begin(), sockets.end(), socket);
    sockets.erase(position);
    shutdown(socket->getIntSocket(), SHUT_RDWR);
    close(socket->getIntSocket());
}

void ListaSockets::cerrarSockets() {
    lock_guard<mutex> lock(m);
    for(Socket *socket : sockets){
        shutdown(socket->getIntSocket(), SHUT_RDWR);
        close(socket->getIntSocket());
    }
    Locator::logger()->log(INFO, "Se cerraron los sockets hacia los clientes.");
}