//
// Created by sebas on 9/10/19.
//

#ifndef FINAL_FIGHT_SOCKET_H
#define FINAL_FIGHT_SOCKET_H


#include <sstream>

using namespace std;

class Socket {

private:
    int socket;
    int tamanoDigitos = 5;
    bool enviarSinChequeo(stringstream &s);
    bool recibirConCantidad(stringstream &s, size_t cantidad);

public:
    explicit Socket(int socket);
    bool enviar(stringstream &s);
    bool recibir(stringstream &s);
    int getIntSocket();
};


#endif //FINAL_FIGHT_SOCKET_H
