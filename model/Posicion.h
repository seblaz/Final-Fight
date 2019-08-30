//
// Created by sebas on 30/8/19.
//

#ifndef FINAL_FIGHT_POSICION_H
#define FINAL_FIGHT_POSICION_H


#include "Direccion.h"

class Posicion {
    private:
        int x, y, z;
    public:
        Posicion(int x, int y, int z);
        void mover(Direccion& direccion);
};


#endif //FINAL_FIGHT_POSICION_H
