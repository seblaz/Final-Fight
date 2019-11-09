//
// Created by sebas on 8/11/19.
//

#ifndef FINAL_FIGHT_VISTAFIN_H
#define FINAL_FIGHT_VISTAFIN_H


#include <SDL_render.h>
#include "Vista.h"

class VistaFin : public Vista {

public:
    void graficar(SDL_Renderer *renderer) override;
    
};


#endif //FINAL_FIGHT_VISTAFIN_H
