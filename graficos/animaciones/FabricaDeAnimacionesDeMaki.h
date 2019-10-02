//
// Created by sebas on 14/9/19.
//

#ifndef FINAL_FIGHT_FABRICADEANIMACIONESDEMAKI_H
#define FINAL_FIGHT_FABRICADEANIMACIONESDEMAKI_H


#include "Animacion.h"
#include "FabricaDeAnimacionesDePersonaje.h"

class FabricaDeAnimacionesDeMaki : public FabricaDeAnimacionesDePersonaje {

public:
    Animacion* caminando() override;
    Animacion* saltando() override;
    Animacion* reposando() override;
    Animacion* agachado() override;
    Animacion* golpear() override;
    Animacion* saltandoAdelante() override;
    Animacion* patadaBasica() override;

};

#endif //FINAL_FIGHT_FABRICADEANIMACIONESDEMAKI_H