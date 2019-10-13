//
// Created by sebas on 12/10/19.
//

#include "ListaSockets.h"

void ListaSockets::agregar(Socket socket) {
    lock_guard<mutex> lock(m);
    sockets.push_back(socket);
}

vector<Socket> ListaSockets::devolverSockets() {
    lock_guard<mutex> lock(m);
    return vector<Socket>(sockets);
}
