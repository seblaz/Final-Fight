//
// Created by sebas on 14/9/19.
//

#ifndef FINAL_FIGHT_COMPORTAMIENTONULO_H
#define FINAL_FIGHT_COMPORTAMIENTONULO_H


#include "Comportamiento.h"

class ComportamientoNulo : public Comportamiento {
    void actualizar() override {};
    Animacion* devolverAnimacion(){};
};


#endif //FINAL_FIGHT_COMPORTAMIENTONULO_H
