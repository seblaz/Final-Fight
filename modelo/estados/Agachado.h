//
// Created by franco on 8/9/19.
//

#ifndef FINAL_FIGHT_AGACHADO_H
#define FINAL_FIGHT_AGACHADO_H

#include "EstadoDePersonaje.h"

class Agachado : public EstadoDePersonaje{

public:
    Agachado();
    ~Agachado();
    EstadoDePersonaje *manejarEntrada(Personaje& personaje, const Uint8* entrada) override;
    virtual void enter(){};

};

#endif //FINAL_FIGHT_AGACHADO_H
