//
// Created by sebas on 6/11/19.
//

#include "InterpreteAutenticadorCli.h"

InterpreteAutenticadorCli::InterpreteAutenticadorCli(VistaAutenticador *vista, ManagerPantallas *pantallas) :
        vista(vista),
        pantallas(pantallas) {}

void InterpreteAutenticadorCli::interpretar(stringstream &s) {
    EventoUsuario evento;
    evento.deserializar(s);
    switch (evento.evento()) {
        case EVENTO_USUARIO::CONTRASENIA_INCORRECTA:
            vista->passwordIncorrecta();
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
