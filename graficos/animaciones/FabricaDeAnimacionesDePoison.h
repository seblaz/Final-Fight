//
// Created by sebas on 13/9/19.
//


#ifndef FINAL_FIGHT_FABRICADEANIMACIONESDEPOISON_H
#define FINAL_FIGHT_FABRICADEANIMACIONESDEPOISON_H


#include "Animacion.h"
#include "FabricaDeAnimacionesDePersonaje.h"

class FabricaDeAnimacionesDePoison : public FabricaDeAnimacionesDePersonaje{

public:
    Animacion* caminando() override ;
    Animacion* saltando() override ;
    Animacion* reposando() override ;
    Animacion* agachado() override ;
    Animacion* golpear() override ;
    Animacion* saltandoAdelante() override ;
    Animacion* patadaBasica() override ;
};


#endif //FINAL_FIGHT_FABRICADEANIMACIONESDEPOISON_H
