//
// Created by sebas on 1/9/19.
//

#ifndef FINAL_FIGHT_GRAPHICS_H
#define FINAL_FIGHT_GRAPHICS_H


#include <SDL_surface.h>

//#include "../model/Mapeable.h"
class Mapeable;

class Graphics {

public:
    virtual void actualizar(SDL_Surface *surface, Mapeable &mapeable) = 0;
    virtual ~Graphics() = default;
};


#endif //FINAL_FIGHT_GRAPHICS_H
