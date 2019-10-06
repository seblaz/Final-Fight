//
// Created by sebas on 4/10/19.
//

#include <iostream>
#include <string>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
#include "ConexionCliente.h"
#include "../servicios/Locator.h"

using namespace std;

//Client side
int main(int argc, char *argv[]) {
    auto *logger = new Logger();
    Locator::provide(logger);

    ConexionCliente conexion("localhost", 5000);
    int socket = conexion.socket();
    string data;
    getline(cin, data);
    send(socket, data.c_str(), strlen(data.c_str()), 0);
}