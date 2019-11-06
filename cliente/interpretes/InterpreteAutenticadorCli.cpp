//
// Created by sebas on 6/11/19.
//

#include "InterpreteAutenticadorCli.h"

InterpreteAutenticadorCli::InterpreteAutenticadorCli(Autenticador *autenticador, ManagerPantallas *pantallas) :
        pantallas(pantallas),
        autenticador(autenticador) {}

void InterpreteAutenticadorCli::interpretar(stringstream &s) {
    EventoUsuario evento;
    evento.deserializar(s);
    switch (evento.evento()) {
        case EVENTO_USUARIO::CONTRASENIA_INCORRECTA:
            autenticador->setPasswordIncorrecta();
            break;
        case EVENTO_USUARIO::USUARIO_YA_CONECTADO:
            pantallas->cambiarA("usuario ya conectado");
            break;
        case EVENTO_USUARIO::PARTIDA_LLENA:
            pantallas->cambiarA("partida llena");
            break;
        case EVENTO_USUARIO::NULO:
            break;
    }
}
