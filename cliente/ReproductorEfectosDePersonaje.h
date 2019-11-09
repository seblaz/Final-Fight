//
// Created by poncio on 23/9/19.
//

#ifndef FINAL_FIGHT_REPRODUCTOREFECTOSDEPERSONAJE_H
#define FINAL_FIGHT_REPRODUCTOREFECTOSDEPERSONAJE_H

#include "../modelo/Entidad.h"

class ReproductorEfectosDePersonaje : public Comportamiento{

public:
    void actualizar(Entidad *) override ;
};

#endif //FINAL_FIGHT_REPRODUCTOREFECTOSDEPERSONAJE_H
