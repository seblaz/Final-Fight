//
// Created by sebas on 5/11/19.
//

#include "ModeloAutenticacion.h"

void ModeloAutenticacion::serializar(ostream &stream) {
    Modelo::serializar(stream);
    {
        lock_guard<mutex> lock(m);
        serializarEntero(stream, static_cast<int>(evento));
    }
}

void ModeloAutenticacion::deserializar(istream &stream) {
    Modelo::deserializar(stream);
    evento = static_cast<EVENTO_USUARIO>(deserializarEntero(stream));
}

void ModeloAutenticacion::passwordIncorrecta() {
    lock_guard<mutex> lock(m);
    evento = EVENTO_USUARIO::CONTRASENIA_INCORRECTA;
}

void ModeloAutenticacion::usuarioYaConectado() {
    lock_guard<mutex> lock(m);
    evento = EVENTO_USUARIO::USUARIO_YA_CONECTADO;
}

void ModeloAutenticacion::partidaCompleta() {
    lock_guard<mutex> lock(m);
    evento = EVENTO_USUARIO::PARTIDA_LLENA;
}
