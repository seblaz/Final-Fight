//
// Created by franco on 13/9/19.
//

#ifndef FINAL_FIGHT_MOVERARRIBA_H
#define FINAL_FIGHT_MOVERARRIBA_H

#include "EstadoDePersonaje.h"

class MoverArriba : public EstadoDePersonaje{

public:
    MoverArriba();
    ~MoverArriba();
    virtual void manejarEntrada(Personaje& personaje);
    virtual void enter(){};
};

#endif //FINAL_FIGHT_MOVERARRIBA_H