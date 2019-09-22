//
// Created by sebas on 21/9/19.
//

#ifndef FINAL_FIGHT_ESTADODEPERSONAJE_H
#define FINAL_FIGHT_ESTADODEPERSONAJE_H


#include "../modelo/Entidad.h"

class EstadoDePersonaje : public Comportamiento {

public:
    virtual void enter(Entidad* entidad) = 0;

};


#endif //FINAL_FIGHT_ESTADODEPERSONAJE_H
