//
// Created by sebas on 12/10/19.
//

#ifndef FINAL_FIGHT_ACTUALIZADORUSUARIO_H
#define FINAL_FIGHT_ACTUALIZADORUSUARIO_H


#include "Actualizador.h"
#include "../../usuario/ManagerUsuarios.h"

using namespace std;

class ActualizadorUsuario : public Actualizador {

private:
    bool fin_ = false;
    ManagerUsuarios *manager;
    
public:
    explicit ActualizadorUsuario(ManagerUsuarios *manager);
    void interpretarStream(stringstream &s) override;
    bool fin() override;

};


#endif //FINAL_FIGHT_ACTUALIZADORUSUARIO_H
