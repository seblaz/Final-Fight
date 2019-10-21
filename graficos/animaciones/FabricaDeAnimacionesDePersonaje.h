//
// Created by sebas on 24/9/19.
//

#ifndef FINAL_FIGHT_FABRICADEANIMACIONESDEPERSONAJE_H
#define FINAL_FIGHT_FABRICADEANIMACIONESDEPERSONAJE_H

#include "AnimacionCliente.h"

class FabricaDeAnimacionesDePersonaje : public Estado{

public:
    virtual AnimacionCliente* caminando() = 0;
    virtual AnimacionCliente* saltando() = 0;
    virtual AnimacionCliente* reposando() = 0;
    virtual AnimacionCliente* agachado() = 0;
    virtual AnimacionCliente* golpear() = 0;
    virtual AnimacionCliente* saltandoAdelante() = 0;
    virtual AnimacionCliente* patadaBasica() = 0;

};


#endif //FINAL_FIGHT_FABRICADEANIMACIONESDEPERSONAJE_H
