//
// Created by sebas on 5/11/19.
//

#ifndef FINAL_FIGHT_MANAGERETAPAS_H
#define FINAL_FIGHT_MANAGERETAPAS_H


#include <list>
#include "Etapa.h"

using namespace std;

class ManagerEtapas {

private:
    Etapa *actual = nullptr;
    map<IdEtapa, Etapa *> etapas;
    mutex m;

public:
    void agregar(Etapa *etapa);
    Etapa *getActual();
    void cambiarA(const IdEtapa& id);
};


#endif //FINAL_FIGHT_MANAGERETAPAS_H
