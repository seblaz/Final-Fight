//
// Created by sebas on 4/10/19.
//

#ifndef FINAL_FIGHT_CONEXIONSERVIDOR_H
#define FINAL_FIGHT_CONEXIONSERVIDOR_H

#include <iostream>
#include <string>
#include <cstdio>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstdlib>
#include <unistd.h>
#include <cstring>
#include <netdb.h>
#include <sys/uio.h>
#include <ctime>
#include <sys/wait.h>
#include <fcntl.h>
#include <fstream>
#include <vector>
#include "../utils/Socket.h"

using namespace std;

class ConexionServidor {

private:
    int descriptorSocket {};

public:
    explicit ConexionServidor(int puerto);
    Socket *socket();

};

#endif //FINAL_FIGHT_CONEXIONSERVIDOR_H
