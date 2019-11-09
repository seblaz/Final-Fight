//
// Created by sebas on 6/11/19.
//

#ifndef FINAL_FIGHT_VISTAJUEGO_H
#define FINAL_FIGHT_VISTAJUEGO_H


#include <SDL_system.h>
#include "Vista.h"

class VistaJuego : public Vista {



public:
    void graficar(SDL_Renderer *renderer) override;
    void reproducir() override;
};


#endif //FINAL_FIGHT_VISTAJUEGO_H
