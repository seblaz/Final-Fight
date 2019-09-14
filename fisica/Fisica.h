//
// Created by sebas on 1/9/19.
//

#ifndef FINAL_FIGHT_FISICA_H
#define FINAL_FIGHT_FISICA_H

#include "../modelo/mapeables/Mapeable.h"
#include "../modelo/Mapa.h"

class Fisica {

public:
    virtual ~Fisica() = default;
    virtual void actualizar(Mapa& mapa, Mapeable& mapeable) = 0;
};

#endif //FINAL_FIGHT_FISICA_H
