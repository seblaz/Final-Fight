//
// Created by sebas on 30/8/19.
//

#ifndef FINAL_FIGHT_MAPEABLE_H
#define FINAL_FIGHT_MAPEABLE_H


#include "Posicion.h"

using namespace std;

class Mapeable {

private:
    Posicion posicion;

public:
    Mapeable(int x, int y, int z);
};


#endif //FINAL_FIGHT_MAPEABLE_H
