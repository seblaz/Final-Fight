//
// Created by franco on 8/9/19.
//

#ifndef FINAL_FIGHT_AGACHAR_H
#define FINAL_FIGHT_AGACHAR_H

#include "EstadoDePersonaje.h"

class Agachar : public EstadoDePersonaje{

public:
    Agachar();
    ~Agachar();
    void manejarEntrada(Personaje& personaje) override;
    virtual void enter(){};

};

#endif //FINAL_FIGHT_AGACHAR_H
