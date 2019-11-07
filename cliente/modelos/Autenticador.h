//
// Created by sebas on 1/11/19.
//

#ifndef FINAL_FIGHT_AUTENTICADOR_H
#define FINAL_FIGHT_AUTENTICADOR_H


#include "../../modelo/serializables/EventoUsuario.h"
#include "../../utils/Socket.h"

class Autenticador {

private:
    string user = "";
    string pass = "";
    string* campoActivo = &user;
    int framesFaltantesPasswordIncorrecta = 0;
    int framesTotalesPasswordIncorrecta = 60;

public:
    void ingresar(char *i);
    void borrar();
    void cambiarCampo();
    string getUsuario();
    string getPassword();
    void setPasswordIncorrecta();
    bool passwordIncorrecta();
};


#endif //FINAL_FIGHT_AUTENTICADOR_H
