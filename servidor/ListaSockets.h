//
// Created by sebas on 12/10/19.
//

#ifndef FINAL_FIGHT_LISTASOCKETS_H
#define FINAL_FIGHT_LISTASOCKETS_H


#include <mutex>
#include <vector>
#include "../modelo/Socket.h"

using namespace std;

class ListaSockets {

private:
    mutex m;
    vector<Socket> sockets;

public:
    void cerrarSockets();
    void agregar(Socket socket);
    vector<Socket> devolverSockets();
    void quitar(Socket socket);

};


#endif //FINAL_FIGHT_LISTASOCKETS_H
