//
// Created by sebas on 5/10/19.
//

#ifndef FINAL_FIGHT_CONEXIONCLIENTE_H
#define FINAL_FIGHT_CONEXIONCLIENTE_H

#include <string>

using namespace std;

class ConexionCliente {

private:
    int descriptorSocket;

public:
    ConexionCliente(const string& ip, int puerto);
    ~ConexionCliente();
    int socket();
};

#endif //FINAL_FIGHT_CONEXIONCLIENTE_H
