//
// Created by franco on 6/9/19.
//

#ifndef FINAL_FIGHT_ESTADOSDEPERSONAJE_H
#define FINAL_FIGHT_ESTADOSDEPERSONAJE_H

#include "../mapeables/Personaje.h"
#include <SDL_system.h>

class EstadosDePersonaje{

public:
    virtual EstadosDePersonaje *manejarEntrada(Personaje& personaje, const Uint8* entrada){};
    virtual void actualizar(Personaje& personaje){};

};

#endif //FINAL_FIGHT_ESTADOSDEPERSONAJE_H
