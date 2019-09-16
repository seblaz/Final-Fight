//
// Created by franco on 6/9/19.
//

#ifndef FINAL_FIGHT_ESTADODEPERSONAJE_H
#define FINAL_FIGHT_ESTADODEPERSONAJE_H

#include <SDL_quit.h>
#include "../../fisica/FisicaDePersonaje.h"
#include "../../graficos/Animacion.h"
#include "../../graficos/FabricaDeAnimacionesDeCody.h"

class EstadoDePersonaje{

public:
    virtual ~EstadoDePersonaje() = default;
    virtual EstadoDePersonaje *manejarEntrada(FisicaDePersonaje *fisica, const Uint8 *currentKeyStates) = 0;
    virtual void actualizar() = 0;
    virtual void enter() = 0;
    virtual Animacion* devolverAnimacion(FabricaDeAnimacionesDeCody *fabrica){};
    //virtual void saltar(){};
    //virtual void mover(){};

};

#endif //FINAL_FIGHT_ESTADODEPERSONAJE_H
