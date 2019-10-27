//
// Created by leo on 20/10/19.
//

#ifndef FINAL_FIGHT_DESCONECTARVOLUNTARIAMENTE_H
#define FINAL_FIGHT_DESCONECTARVOLUNTARIAMENTE_H


#include "Eventos.h"
#include "../usuario/ManagerUsuarios.h"

class DesconectarVoluntariamente : public EventoAProcesar {

private:
    ManagerUsuarios *manager;
    Usuario *usuario;

public:
    explicit DesconectarVoluntariamente(ManagerUsuarios *manager, Usuario* usuario);
    void resolver() override;
};


#endif //FINAL_FIGHT_DESCONECTARVOLUNTARIAMENTE_H
