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
    void actualizar(Entidad *) override;
    void enter(Entidad *) override;
};

#endif //FINAL_FIGHT_CAMINANDO_H
