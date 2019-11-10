//
// Created by sebas on 8/11/19.
//

#ifndef FINAL_FIGHT_VISTAFIN_H
#define FINAL_FIGHT_VISTAFIN_H


#include <SDL_render.h>
#include <string>
#include "Vista.h"

using namespace std;

class VistaFin : public Vista {

public:
    void graficar(SDL_Renderer *renderer) override;
    string getConfigPathMusica() override;

};


#endif //FINAL_FIGHT_VISTAFIN_H
