//
// Created by sebas on 12/10/19.
//

#ifndef FINAL_FIGHT_ACTUALIZADORUSUARIO_H
#define FINAL_FIGHT_ACTUALIZADORUSUARIO_H


#include "Actualizador.h"
#include "../../usuario/ManagerUsuarios.h"
#include "../../eventos/Eventos.h"

using namespace std;

class ManejarUsuario : public EventoAProcesar {

private:
    Usuario *usuario;
    ManagerUsuarios *manager;
    
public:
    ManejarUsuario(Usuario *usuario, ManagerUsuarios *manager);
    void resolver() override;

};

class ActualizadorUsuario : public Actualizador {

private:
    bool fin_ = false;
    EventosAProcesar *eventos;
    ManagerUsuarios *manager;
    
public:
    explicit ActualizadorUsuario(EventosAProcesar *eventos, ManagerUsuarios *manager);
    void interpretarStream(stringstream &s) override;
    bool fin() override;

};


#endif //FINAL_FIGHT_ACTUALIZADORUSUARIO_H
