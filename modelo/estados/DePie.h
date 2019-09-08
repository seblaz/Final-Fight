//
// Created by franco on 6/9/19.
//

#ifndef FINAL_FIGHT_DEPIE_H
#define FINAL_FIGHT_DEPIE_H

#include "EstadosDePersonaje.h"
#include "Saltando.h"

class DePie : public EstadosDePersonaje{

private:

public:
    virtual EstadosDePersonaje *manejarEntrada(Personaje& personaje, const Uint8* entrada);
    virtual void actualizar(Personaje& personaje);
};

#endif //FINAL_FIGHT_DEPIE_H
