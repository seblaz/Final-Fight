//
// Created by sebas on 21/9/19.
//

#ifndef FINAL_FIGHT_ESTADODEPERSONAJE_H
#define FINAL_FIGHT_ESTADODEPERSONAJE_H


#include "../modelo/Entidad.h"

class EstadoDePersonaje : public Comportamiento {

public:
    virtual void enter(Entidad* entidad) = 0;
    virtual void saltar(Entidad *);
    virtual void caminar(Entidad *);
    virtual void reposar(Entidad *);
    virtual void agachar(Entidad *);

};


#endif //FINAL_FIGHT_ESTADODEPERSONAJE_H
