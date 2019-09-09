//
// Created by franco on 6/9/19.
//

#ifndef FINAL_FIGHT_DEPIE_H
#define FINAL_FIGHT_DEPIE_H

#include "EstadoDePersonaje.h"
#include "Saltando.h"

class DePie : public EstadoDePersonaje{

private:

public:
    virtual EstadoDePersonaje *manejarEntrada(Personaje& personaje, const Uint8* entrada);
    virtual void actualizar(Personaje& personaje);
};

#endif //FINAL_FIGHT_DEPIE_H
