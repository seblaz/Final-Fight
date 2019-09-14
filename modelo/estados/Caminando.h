//
// Created by franco on 13/9/19.
//

#ifndef FINAL_FIGHT_CAMINANDO_H
#define FINAL_FIGHT_CAMINANDO_H

#include "EstadoDePersonaje.h"

class Caminando : public EstadoDePersonaje{

public:
    Caminando();
    ~Caminando();
    virtual EstadoDePersonaje *manejarEntrada(Personaje& personaje, const Uint8* entrada);
    virtual void enter(){};
};

#endif //FINAL_FIGHT_CAMINANDO_H
