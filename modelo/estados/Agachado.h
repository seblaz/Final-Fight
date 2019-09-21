//
// Created by franco on 8/9/19.
//

#ifndef FINAL_FIGHT_AGACHADO_H
#define FINAL_FIGHT_AGACHADO_H

#include "EstadoDePersonaje.h"
#include <SDL_scancode.h>
#include "Parado.h"
#include "Golpeando.h"
#include "../../servicios/Logger.h"

class Agachado : public EstadoDePersonaje{

public:
    Agachado();
    ~Agachado() override;
    EstadoDePersonaje *manejarEntrada(FisicaDePersonaje *fisica, const Uint8 *currentKeyStates) override;
    void enter() override {};
    void actualizar() override {};
    Animacion *devolverAnimacion();

};

#endif //FINAL_FIGHT_AGACHADO_H
