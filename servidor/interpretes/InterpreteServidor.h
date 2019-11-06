//
// Created by sebas on 5/11/19.
//

#ifndef FINAL_FIGHT_INTERPRETESERVIDOR_H
#define FINAL_FIGHT_INTERPRETESERVIDOR_H

#include <sstream>
#include "../../modelo/serializables/Accion.h"
#include "../../usuario/Usuario.h"
#include "../../eventos/Eventos.h"

using namespace std;

class InterpreteServidor {

private:
    Usuario *usuario;
    void desconectarUsuario();

public:
    explicit InterpreteServidor(Usuario *usuario);
    Usuario *getUsuario();
    bool interpretarStream(stringstream &s);
    virtual bool interpretarAccion(ACCION accion, stringstream &s) = 0;

};

class DesconectarVoluntariamente : public EventoAProcesar {

private:
    Usuario *usuario;

public:
    explicit DesconectarVoluntariamente(Usuario* usuario);
    void resolver() override;
};

#endif //FINAL_FIGHT_INTERPRETESERVIDOR_H
