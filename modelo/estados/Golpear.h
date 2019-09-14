//
// Created by franco on 8/9/19.
//

#ifndef FINAL_FIGHT_GOLPEAR_H
#define FINAL_FIGHT_GOLPEAR_H

#include "EstadoDePersonaje.h"

class Golpear : public EstadoDePersonaje{

public:
    Golpear();
    ~Golpear();
    void manejarEntrada(Personaje& personaje) override;
    virtual void enter(){};

};

#endif //FINAL_FIGHT_GOLPEAR_H
