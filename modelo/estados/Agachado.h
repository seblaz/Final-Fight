//
// Created by franco on 8/9/19.
//

#ifndef FINAL_FIGHT_AGACHADO_H
#define FINAL_FIGHT_AGACHADO_H

#include "EstadoDePersonaje.h"

class Agachado : public EstadoDePersonaje{

public:
    Agachado();
    ~Agachado();
    EstadoDePersonaje *manejarEntrada(FisicaDePersonaje *fisica, const Uint8 *currentKeyStates) override;
    void enter() override {};
    void actualizar() override {};

};

#endif //FINAL_FIGHT_AGACHADO_H
