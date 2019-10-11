//
// Created by sebas on 9/10/19.
//

#include <sys/socket.h>
#include <cstring>
#include "Socket.h"
#include "../servicios/Locator.h"

Socket::Socket(int socket) : socket(socket) {}

bool Socket::enviarSinChequeo(stringstream &s) {
    string msg = s.str();
    size_t total = 0;
    size_t tamano = msg.size();
    size_t enviados;

    do {
        enviados = send(socket, msg.c_str() + total, tamano - total, 0);
        total += enviados;
    } while ((enviados > 0) && (tamano != total));

    if (enviados == -1) {
        Locator::logger()->log(ERROR, "Ocurrió un error al enviar por el socket: " + string(strerror(errno)));
        return false;
    }
    return enviados != 0;
}

bool Socket::enviar(stringstream &s) {
    string msg = s.str();
    size_t tamano = msg.size();

//    Locator::logger()->log(DEBUG, "Se pretende enviar un mensaje de tamaño: " + to_string((tamano)));
//    Locator::logger()->log(DEBUG, "Con el mensaje: " + msg);

    std::stringstream ss;
    ss << std::setw(tamanoDigitos) << std::setfill('0') << tamano;

    bool resultado = enviarSinChequeo(ss) && enviarSinChequeo(s);
//    Locator::logger()->log(DEBUG, "Mensaje enviado con resultado: " + to_string(resultado));
    return resultado;
}

bool Socket::recibirConCantidad(stringstream &s, size_t cantidad) {
    char buffer[cantidad + 1];
//    memset(&buffer, 0, sizeof(buffer)); // clear the buffer

    size_t leidos;
    size_t total = 0;
    size_t tamano = cantidad;

    do {
        leidos = recv(socket, buffer + total, tamano - total, 0);
        total += leidos;
    } while ((leidos > 0) && (total != tamano));

    s << buffer;

    if (leidos == -1) {
        Locator::logger()->log(ERROR, "Ocurrió un error al recibir por el socket: " + string(strerror(errno)));
        return false;
    }
    return leidos != 0;
}

bool Socket::recibir(stringstream &s) {
//    Locator::logger()->log(DEBUG, "Comienzo a recibir.");

    stringstream ss;
    bool res1 = recibirConCantidad(ss, tamanoDigitos);
    int tamanoPaquete;
    ss >> tamanoPaquete;

    if(!res1){
        Locator::logger()->log(ERROR, "No se pudo recibir el mensaje.");
        return false;
    }

    bool res2 = recibirConCantidad(s, tamanoPaquete);

    if(!res2){
        Locator::logger()->log(ERROR, "No se pudo recibir el mensaje.");
        return false;
    }

//    Locator::logger()->log(DEBUG, "Mensaje recibido: " + s.str());
    return res2;
}

