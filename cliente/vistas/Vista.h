//
// Created by sebas on 6/11/19.
//

#ifndef FINAL_FIGHT_VISTA_H
#define FINAL_FIGHT_VISTA_H

#include <SDL_render.h>
#include <string>

using namespace std;

class Vista {

public:
    virtual void graficar(SDL_Renderer *renderer) = 0;
    virtual string getConfigPathMusica() = 0;
    virtual int getLoops();

    virtual void reproducir();

};

#endif //FINAL_FIGHT_VISTA_H
