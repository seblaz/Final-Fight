//
// Created by sebas on 1/9/19.
//

#ifndef FINAL_FIGHT_GRAFICO_H
#define FINAL_FIGHT_GRAFICO_H


#include <SDL_system.h>

class Grafico {

public:
    virtual void actualizar(SDL_Renderer *renderer) = 0;
};


#endif //FINAL_FIGHT_GRAFICO_H
