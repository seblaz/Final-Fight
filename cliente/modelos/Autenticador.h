//
// Created by sebas on 1/11/19.
//

#ifndef FINAL_FIGHT_AUTENTICADOR_H
#define FINAL_FIGHT_AUTENTICADOR_H


#include "../../modelo/serializables/EventoUsuario.h"
#include "../../modelo/Socket.h"

class Autenticador {

private:
    string user = "";
    string pass = "";
    string* campoActivo = &user;

public:
    void ingresar(char *i);
    void borrar();
    void cambiarCampo();
    string getUsuario();
    string getPassword();

};


#endif //FINAL_FIGHT_AUTENTICADOR_H
