//
// Created by franco on 6/9/19.
//

#ifndef FINAL_FIGHT_ESTADODEPERSONAJE_H
#define FINAL_FIGHT_ESTADODEPERSONAJE_H

#include "../mapeables/Personaje.h"
#include "../../servicios/Logger.h"
#include <SDL_system.h>

//-Se considerara S como tecla de salto
//-Las teclas de movimiento seran las del teclado

class EstadoDePersonaje{

public:
    virtual void manejarEntrada(Personaje& personaje){};
    virtual void actualizar(Personaje& personaje){};
    virtual void enter(){};
    virtual ~EstadoDePersonaje(){};
};

#endif //FINAL_FIGHT_ESTADODEPERSONAJE_H
