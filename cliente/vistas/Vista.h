//
// Created by sebas on 6/11/19.
//

#ifndef FINAL_FIGHT_VISTA_H
#define FINAL_FIGHT_VISTA_H

class Vista {

public:
    virtual void graficar(SDL_Renderer *renderer) = 0;
    virtual void reproducir() = 0;
};

#endif //FINAL_FIGHT_VISTA_H
