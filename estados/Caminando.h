//
// Created by franco on 13/9/19.
//

#ifndef FINAL_FIGHT_CAMINANDO_H
#define FINAL_FIGHT_CAMINANDO_H

#include "EstadoDePersonaje.h"
#include <SDL_scancode.h>


class Caminando : public EstadoDePersonaje {

public:
    Caminando();
    ~Caminando();
    void enter(Entidad *) override;
    void caminar(Entidad *, bool X_pos, bool X_neg, bool Y_pos, bool Y_neg) override;
};

#endif //FINAL_FIGHT_CAMINANDO_H
