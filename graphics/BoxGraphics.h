//
// Created by sebas on 2/9/19.
//

#ifndef FINAL_FIGHT_BOXGRAPHICS_H
#define FINAL_FIGHT_BOXGRAPHICS_H


#include "Graphics.h"

class BoxGraphics : public Graphics{
private:
    SDL_Surface *gHelloWorld = nullptr;

public:
    virtual void actualizar(SDL_Surface *surface, Mapeable &mapeable);
    ~BoxGraphics();
};


#endif //FINAL_FIGHT_BOXGRAPHICS_H
