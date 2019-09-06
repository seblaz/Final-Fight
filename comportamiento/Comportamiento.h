//
// Created by sebas on 2/9/19.
//

#ifndef FINAL_FIGHT_COMPORTAMIENTO_H
#define FINAL_FIGHT_COMPORTAMIENTO_H


#include "../modelo/mapeables/Mapeable.h"

class Comportamiento {

public:
    virtual void actualizar(Mapeable &mapeable) = 0;
    virtual ~Comportamiento() = default;
};


#endif //FINAL_FIGHT_COMPORTAMIENTO_H
