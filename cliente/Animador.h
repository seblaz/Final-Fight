//
// Created by franco on 23/9/19.
//

#ifndef FINAL_FIGHT_ANIMADOR_H
#define FINAL_FIGHT_ANIMADOR_H

#include "../modelo/Entidad.h"

class Animador : public Comportamiento{

public:
    void actualizar(Entidad *) override ;
};

#endif //FINAL_FIGHT_ANIMADOR_H
