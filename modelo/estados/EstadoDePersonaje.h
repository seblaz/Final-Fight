//
// Created by franco on 6/9/19.
//

#ifndef FINAL_FIGHT_ESTADODEPERSONAJE_H
#define FINAL_FIGHT_ESTADODEPERSONAJE_H

#include "../mapeables/Personaje.h"
#include <SDL_system.h>

class EstadoDePersonaje{

public:
    virtual EstadoDePersonaje *manejarEntrada(Personaje& personaje, const Uint8* entrada){};
    virtual void actualizar(Personaje& personaje){};

};

#endif //FINAL_FIGHT_ESTADODEPERSONAJE_H
