//
// Created by sebas on 30/8/19.
//

#ifndef FINAL_FIGHT_POSICION_H
#define FINAL_FIGHT_POSICION_H


#include "Velocidad.h"
#include "mapeables/Entidad.h"

class Posicion : public Estado{

private:
    int x, y, z;

public:
    Posicion(int x, int y, int z);
    Posicion operator-(Posicion otraPosicion);
    void mover(Velocidad& velocidad);
    int getX();
    int getY();
    int getZ();
    void setX(int x);
};


#endif //FINAL_FIGHT_POSICION_H
