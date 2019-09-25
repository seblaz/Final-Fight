//
// Created by sebas on 14/9/19.
//

#ifndef FINAL_FIGHT_FABRICADEANIMACIONESDEAXL_H
#define FINAL_FIGHT_FABRICADEANIMACIONESDEAXL_H


#include "Animacion.h"

class FabricaDeAnimacionesDeAxl {

public:
    static Animacion* caminado();
    static Animacion* saltando();
    static Animacion* parado();
    static Animacion* agachado();
    static Animacion* golpear();

};


#endif //FINAL_FIGHT_FABRICADEANIMACIONESDEAXL_H