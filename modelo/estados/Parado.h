//
// Created by franco on 6/9/19.
//

#ifndef FINAL_FIGHT_PARADO_H
#define FINAL_FIGHT_PARADO_H


#include "EstadoDePersonaje.h"
#include "Saltando.h"
#include "Golpeando.h"
#include "Agachado.h"
#include "Caminando.h"
#include <SDL_system.h>
#include "../../servicios/Logger.h"


class Parado : public EstadoDePersonaje{

private:

public:
    Parado();
    ~Parado() override;
    EstadoDePersonaje *manejarEntrada(FisicaDePersonaje *fisica, const Uint8* entrada) override;
    void actualizar() override {};
    void enter() override {};
    Animacion *devolverAnimacion();
};

#endif //FINAL_FIGHT_PARADO_H
