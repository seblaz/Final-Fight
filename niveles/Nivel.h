//
// Created by felipe on 22/9/19.
//

#ifndef FINAL_FIGHT_NIVEL_H
#define FINAL_FIGHT_NIVEL_H


#include <SDL_system.h>
#include "../modelo/Mapa.h"

class Nivel{


public:
    Nivel();
    static void generarNivel(SDL_Renderer *sdlRenderer, Mapa* mapa, int cantidadDeCajas, int cantidadDeCuchillos);
};
#endif //FINAL_FIGHT_NIVEL_H

