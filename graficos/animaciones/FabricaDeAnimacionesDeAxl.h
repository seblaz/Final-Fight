//
// Created by sebas on 14/9/19.
//

#ifndef FINAL_FIGHT_FABRICADEANIMACIONESDEAXL_H
#define FINAL_FIGHT_FABRICADEANIMACIONESDEAXL_H


#include "AnimacionCliente.h"

class FabricaDeAnimacionesDeAxl {

public:
    static AnimacionCliente* caminado();
    static AnimacionCliente* saltando();
    static AnimacionCliente* parado();
    static AnimacionCliente* agachado();
    static AnimacionCliente* golpear();

};


#endif //FINAL_FIGHT_FABRICADEANIMACIONESDEAXL_H