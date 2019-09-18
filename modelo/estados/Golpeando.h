//
// Created by franco on 13/9/19.
//

#ifndef FINAL_FIGHT_GOLPEANDO_H
#define FINAL_FIGHT_GOLPEANDO_H

#include "EstadoDePersonaje.h"
#include "Saltando.h"
#include "Agachado.h"
#include "Parado.h"
#include "Caminando.h"
#include "../../servicios/Logger.h"
#include <SDL_scancode.h>


class Golpeando : public EstadoDePersonaje{

public:
    Golpeando();
    ~Golpeando() override;
    EstadoDePersonaje *manejarEntrada(FisicaDePersonaje *fisica, const Uint8* entrada) override;
    void enter() override {};
    void actualizar() override {};
    Animacion *devolverAnimacion();
};

#endif //FINAL_FIGHT_GOLPEANDO_H
