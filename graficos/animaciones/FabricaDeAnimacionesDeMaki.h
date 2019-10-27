//
// Created by sebas on 14/9/19.
//

#ifndef FINAL_FIGHT_FABRICADEANIMACIONESDEMAKI_H
#define FINAL_FIGHT_FABRICADEANIMACIONESDEMAKI_H


#include "AnimacionCliente.h"
#include "FabricaDeAnimacionesDePersonaje.h"

class FabricaDeAnimacionesDeMaki : public FabricaDeAnimacionesDePersonaje {

public:
    AnimacionCliente* caminando() override;
    AnimacionCliente* saltando() override;
    AnimacionCliente* reposando() override;
    AnimacionCliente* agachado() override;
    AnimacionCliente* golpear() override;
    AnimacionCliente* saltandoAdelante() override;
    AnimacionCliente* patadaBasica() override;

};

#endif //FINAL_FIGHT_FABRICADEANIMACIONESDEMAKI_H