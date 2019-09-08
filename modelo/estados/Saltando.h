//
// Created by franco on 8/9/19.
//

#ifndef FINAL_FIGHT_SALTANDO_H
#define FINAL_FIGHT_SALTANDO_H

#include "EstadosDePersonaje.h"

class Saltando : public EstadosDePersonaje{

private:
    int alturaMaxima = 10; // Numero de prueba SUPER HARDCODE

public:
    virtual EstadosDePersonaje *manejarEntrada(Personaje& personaje, const Uint8* entrada);
    virtual void actualizar(Personaje& personaje);

};

#endif //FINAL_FIGHT_SALTANDO_H
