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
    EventosAProcesar *eventos;
    ManagerUsuarios *manager;
    semaphore usuarioAgregado;
    bool validarContrasenia(Usuario *usuario, Socket *socket);

public:
    explicit ActualizadorUsuario(EventosAProcesar *eventos, ManagerUsuarios *manager);
    Usuario *getUsuario(Socket *socket);
};


#endif //FINAL_FIGHT_ACTUALIZADORUSUARIO_H
