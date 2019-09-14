//
// Created by franco on 13/9/19.
//

#ifndef FINAL_FIGHT_MOVERDERECHA_H
#define FINAL_FIGHT_MOVERDERECHA_H

#include "EstadoDePersonaje.h"

class MoverDerecha : public EstadoDePersonaje{

public:
    MoverDerecha();
    ~MoverDerecha();
    virtual void manejarEntrada(Personaje& personaje);
    virtual void enter(){};
};

#endif //FINAL_FIGHT_MOVERDERECHA_H