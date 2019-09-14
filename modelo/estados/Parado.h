//
// Created by franco on 13/9/19.
//

#ifndef FINAL_FIGHT_PARADO_H
#define FINAL_FIGHT_PARADO_H

#include "EstadoDePersonaje.h"

class Parado : public EstadoDePersonaje{

public:
    Parado();
    ~Parado();
    virtual void manejarEntrada(Personaje& personaje);
    virtual void enter(){};
};

#endif //FINAL_FIGHT_PARADO_H