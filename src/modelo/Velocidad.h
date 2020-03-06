//
// Created by sebas on 30/8/19.
//

#ifndef FINAL_FIGHT_VELOCIDAD_H
#define FINAL_FIGHT_VELOCIDAD_H


#include "Entidad.h"

/**
 * Modela una direccion. A nivel de implementación es un vector unitario.
 */
class Velocidad:public Estado
{
public:
  float x, y, z;
    Velocidad ();
    Velocidad (float x, float y, float z);
};


#endif //FINAL_FIGHT_VELOCIDAD_H
