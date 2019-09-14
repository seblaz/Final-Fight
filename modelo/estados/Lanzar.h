//
// Created by franco on 8/9/19.
//

#ifndef FINAL_FIGHT_LANZAR_H
#define FINAL_FIGHT_LANZAR_H

#include "EstadoDePersonaje.h"

class Lanzar : public EstadoDePersonaje{

public:
    Lanzar();
    ~Lanzar();
    void manejarEntrada(Personaje& personaje) override;
    virtual void enter(){};

};

#endif //FINAL_FIGHT_LANZAR_H