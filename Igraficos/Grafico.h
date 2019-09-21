//
// Created by sebas on 21/9/19.
//

#ifndef FINAL_FIGHT_GRAFICO_H
#define FINAL_FIGHT_GRAFICO_H


#include "../modelo/mapeables/Entidad.h"

class Grafico : public Comportamiento {

public:
    void actualizar(Entidad*) override;
};


#endif //FINAL_FIGHT_GRAFICO_H
