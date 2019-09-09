//
// Created by sebas on 30/8/19.
//

#ifndef FINAL_FIGHT_POSICION_H
#define FINAL_FIGHT_POSICION_H


#include "Velocidad.h"

class Posicion {

private:
    int x, y, z;

public:
    Posicion(int x, int y, int z);
    void mover(Velocidad& velocidad);
    int getX();
    int getY();
    int getZ();
};


#endif //FINAL_FIGHT_POSICION_H
