//
// Created by sebas on 14/9/19.
//

#ifndef FINAL_FIGHT_COMPORTAMIENTONULO_H
#define FINAL_FIGHT_COMPORTAMIENTONULO_H


#include "IComportamiento.h"

class ComportamientoNulo : public IComportamiento {
    void actualizar() override {};
    Animacion* devolverAnimacion(){};
};


#endif //FINAL_FIGHT_COMPORTAMIENTONULO_H
