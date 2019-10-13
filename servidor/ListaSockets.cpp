//
// Created by sebas on 12/10/19.
//

#include "ListaSockets.h"
#include <algorithm>

void ListaSockets::agregar(Socket socket) {
    lock_guard<mutex> lock(m);
    sockets.push_back(socket);
}

vector<Socket> ListaSockets::devolverSockets() {
    lock_guard<mutex> lock(m);
    return vector<Socket>(sockets);
}

void ListaSockets::quitar(Socket socket) {
    lock_guard<mutex> lock(m);
    auto position = find(sockets.begin(), sockets.end(), socket);
    sockets.erase(position);
}
