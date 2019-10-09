//
// Created by sebas on 5/10/19.
//

#include "Escucha.h"
#include "../modelo/Accion.h"

Escucha::Escucha(Socket socket) :
        socket(socket) {}

void Escucha::escuchar(ActualizadorServidor *actualizador) {

    while (true) {
        stringstream s;
        if(!socket.recibir(s)) break;
        actualizador->interpretarComando(s);
    }
}

