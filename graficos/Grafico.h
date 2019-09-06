//
// Created by sebas on 1/9/19.
//

#ifndef FINAL_FIGHT_GRAFICO_H
#define FINAL_FIGHT_GRAFICO_H


#include <SDL_surface.h>
#include <SDL_system.h>

//#include "../modelo/Mapeable.h"
class Mapeable;

class Grafico {

public:
    virtual void actualizar(SDL_Renderer *renderer, Mapeable &mapeable) = 0;
    virtual ~Grafico() = default;
};


#endif //FINAL_FIGHT_GRAFICO_H
