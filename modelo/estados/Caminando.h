//
// Created by franco on 13/9/19.
//

#ifndef FINAL_FIGHT_CAMINANDO_H
#define FINAL_FIGHT_CAMINANDO_H

#include "EstadoDePersonaje.h"
#include <SDL_scancode.h>
#include "Saltando.h"
#include "Agachado.h"
#include "Parado.h"
#include "Golpeando.h"
#include "../../servicios/Logger.h"


class Caminando : public EstadoDePersonaje{

public:
    Caminando();
    ~Caminando() override;
    EstadoDePersonaje *manejarEntrada(FisicaDePersonaje *fisica, const Uint8* entrada) override;
    void enter() override {};
    void actualizar() override {};
    Animacion *devolverAnimacion();
};

#endif //FINAL_FIGHT_CAMINANDO_H
