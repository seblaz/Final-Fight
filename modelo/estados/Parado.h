//
// Created by franco on 6/9/19.
//

#ifndef FINAL_FIGHT_PARADO_H
#define FINAL_FIGHT_PARADO_H

#include "EstadoDePersonaje.h"
#include "Saltando.h"

class Parado : public EstadoDePersonaje{

private:

public:
    Parado();
    ~Parado();
    virtual EstadoDePersonaje *manejarEntrada(Personaje& personaje, const Uint8* entrada);
    virtual void actualizar(Personaje& personaje){};
    virtual void enter(){};
};

#endif //FINAL_FIGHT_PARADO_H
