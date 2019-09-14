//
// Created by franco on 13/9/19.
//

#ifndef FINAL_FIGHT_MOVERIZQUIERDA_H
#define FINAL_FIGHT_MOVERIZQUIERDA_H

#include "EstadoDePersonaje.h"

class MoverIzquierda : public EstadoDePersonaje{

public:
    MoverIzquierda();
    ~MoverIzquierda();
    virtual void manejarEntrada(Personaje& personaje);
    virtual void enter(){};
};

#endif //FINAL_FIGHT_MOVERIZQUIERDA_H