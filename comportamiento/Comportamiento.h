//
// Created by sebas on 2/9/19.
//

#ifndef FINAL_FIGHT_COMPORTAMIENTO_H
#define FINAL_FIGHT_COMPORTAMIENTO_H


#include "../modelo/mapeables/Mapeable.h"
//#include "../modelo/mapeables/Personaje.h"
//#include "../modelo/estados/EstadoDePersonaje.h"


class Comportamiento {

public:
    virtual void actualizar() = 0;
};


#endif //FINAL_FIGHT_COMPORTAMIENTO_H
