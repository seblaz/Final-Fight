//
// Created by sebas on 1/9/19.
//

#ifndef FINAL_FIGHT_FISICA_H
#define FINAL_FIGHT_FISICA_H

class Mapa;
class Mapeable;

class Fisica {
public:
    virtual void actualizar() = 0;
};

#include "../modelo/Mapa.h"

#endif //FINAL_FIGHT_FISICA_H
