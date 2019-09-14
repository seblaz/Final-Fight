//
// Created by franco on 8/9/19.
//

#ifndef FINAL_FIGHT_SALTAR_H
#define FINAL_FIGHT_SALTAR_H

#include "EstadoDePersonaje.h"

#define LIMITE 30 // Limite del salto en altura

class Saltar : public EstadoDePersonaje{

private:
    int alturaMaxima_ = LIMITE; // Numero de prueba SUPER HARDCODE
    bool subiendo_ = true;

public:
    Saltar();
    ~Saltar();
    virtual void manejarEntrada(Personaje& personaje);
    virtual void actualizar(Personaje& personaje){};
    virtual void enter(){};

};

#endif //FINAL_FIGHT_SALTAR_H
