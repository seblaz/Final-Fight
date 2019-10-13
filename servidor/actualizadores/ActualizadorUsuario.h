//
// Created by sebas on 12/10/19.
//

#ifndef FINAL_FIGHT_ACTUALIZADORUSUARIO_H
#define FINAL_FIGHT_ACTUALIZADORUSUARIO_H


#include "../../usuario/ManagerUsuarios.h"
#include "../../eventos/Eventos.h"

using namespace std;

class AgregarUsuario : public EventoAProcesar {

private:
    Usuario *usuario;
    ManagerUsuarios *manager;
    semaphore &usuarioAgregado;

public:
    AgregarUsuario(Usuario *usuario, ManagerUsuarios *manager, semaphore &semaphore);
    void resolver() override;

};

class ActualizadorUsuario {

private:
    bool fin_ = false;
    EventosAProcesar *eventos;
    ManagerUsuarios *manager;
    semaphore usuarioAgregado;

public:
    explicit ActualizadorUsuario(EventosAProcesar *eventos, ManagerUsuarios *manager);
    Usuario *interpretarStream(stringstream &s, Socket socket);
    bool fin();

};


#endif //FINAL_FIGHT_ACTUALIZADORUSUARIO_H
