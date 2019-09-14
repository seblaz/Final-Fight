//
// Created by franco on 13/9/19.
//

#ifndef FINAL_FIGHT_MOVERABAJO_H
#define FINAL_FIGHT_MOVERABAJO_H

#include "EstadoDePersonaje.h"

class MoverAbajo : public EstadoDePersonaje{

public:
    MoverAbajo();
    ~MoverAbajo();
    virtual void manejarEntrada(Personaje& personaje);
    virtual void enter(){};
};

#endif //FINAL_FIGHT_MOVERABAJO_H