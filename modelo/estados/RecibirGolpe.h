//
// Created by franco on 8/9/19.
//

#ifndef FINAL_FIGHT_RECIBIRGOLPE_H
#define FINAL_FIGHT_RECIBIRGOLPE_H

#include "EstadoDePersonaje.h"

class RecibirGolpe : public EstadoDePersonaje{

public:
    RecibirGolpe();
    ~RecibirGolpe();
    void manejarEntrada(Personaje& personaje) override;
    virtual void enter(){};

};

#endif //FINAL_FIGHT_RECIBIRGOLPE_H
