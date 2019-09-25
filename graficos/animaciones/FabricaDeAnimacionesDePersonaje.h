//
// Created by sebas on 24/9/19.
//

#ifndef FINAL_FIGHT_FABRICADEANIMACIONESDEPERSONAJE_H
#define FINAL_FIGHT_FABRICADEANIMACIONESDEPERSONAJE_H

#include "Animacion.h"

class FabricaDeAnimacionesDePersonaje : public Estado{

public:
    virtual Animacion* caminando() = 0;
    virtual Animacion* saltando() = 0;
    virtual Animacion* reposando() = 0;
    virtual Animacion* agachado() = 0;
    virtual Animacion* golpear() = 0;
    virtual Animacion* saltandoAdelante() = 0;
    virtual Animacion* patadaBasica() = 0;

};


#endif //FINAL_FIGHT_FABRICADEANIMACIONESDEPERSONAJE_H
