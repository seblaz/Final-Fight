//
// Created by sebas on 5/10/19.
//

#include <netdb.h>
#include "ConexionCliente.h"
#include "../servicios/Locator.h"
#include <cstring>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <cstdlib>
#include <unistd.h>

ConexionCliente::ConexionCliente(const string &ip, int puerto) {

    struct hostent *host = gethostbyname(ip.c_str());
    sockaddr_in sendSockAddr{};
    bzero((char *) &sendSockAddr, sizeof(sendSockAddr));
    sendSockAddr.sin_family = AF_INET;
    sendSockAddr.sin_addr.s_addr = inet_addr(inet_ntoa(*(struct in_addr *) *host->h_addr_list));
    sendSockAddr.sin_port = htons(puerto);
    descriptorSocket = ::socket(AF_INET, SOCK_STREAM, 0);
    int status = connect(descriptorSocket, (sockaddr *) &sendSockAddr, sizeof(sendSockAddr));
    if (status < 0) {
        Locator::logger()->log(ERROR, "El cliente no pudo conectarse al servidor.");
        exit(0);
    } else {
        Locator::logger()->log(INFO, "El cliente se conectó al servidor.");
    }

}

ConexionCliente::~ConexionCliente() {
    close(descriptorSocket);
    Locator::logger()->log(INFO, "Se terminó la conexión con el servidor.");
}

Socket ConexionCliente::socket() {
    return Socket(descriptorSocket);
}
