//
// Created by sebas on 14/9/19.
//

#ifndef FINAL_FIGHT_FABRICADEANIMACIONESDEANDORE_H
#define FINAL_FIGHT_FABRICADEANIMACIONESDEANDORE_H


#include "Animacion.h"

class FabricaDeAnimacionesDeAndore {

public:
    static Animacion* caminado();
    static Animacion* saltando();
    static Animacion* parado();
    static Animacion* agachado();
    static Animacion* golpear();

};


#endif //FINAL_FIGHT_FABRICADEANIMACIONESDEANDORE_H
