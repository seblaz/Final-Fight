//
// Created by sebas on 16/11/19.
//

#ifndef FINAL_FIGHT_ESTADODECOLISIONABLE_H
#define FINAL_FIGHT_ESTADODECOLISIONABLE_H

#include "../modelo/Entidad.h"

class EstadoDeColisionable : public Comportamiento {

public:
    using Comportamiento::Comportamiento;
    virtual void recibirGolpeDe(Entidad *jugador) = 0;

};

#endif //FINAL_FIGHT_ESTADODECOLISIONABLE_H
