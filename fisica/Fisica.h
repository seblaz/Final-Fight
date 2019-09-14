//
// Created by sebas on 1/9/19.
//

#ifndef FINAL_FIGHT_FISICA_H
#define FINAL_FIGHT_FISICA_H

class Mapa;
class Mapeable;

class Fisica {

public:
    virtual ~Fisica() = default;
    virtual void actualizar(Mapa& mapa, Mapeable& mapeable) = 0;
};

#include "../modelo/mapeables/Mapeable.h"
#include "../modelo/Mapa.h"

#endif //FINAL_FIGHT_FISICA_H
