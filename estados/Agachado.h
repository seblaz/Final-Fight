//
// Created by franco on 8/9/19.
//

#ifndef FINAL_FIGHT_AGACHADO_H
#define FINAL_FIGHT_AGACHADO_H

#include "EstadoDePersonaje.h"
#include <SDL_scancode.h>
#include "Reposando.h"
#include "../servicios/Logger.h"

class Agachado : public EstadoDePersonaje {

public:
    Agachado();
    ~Agachado();

    void agachar(Entidad *) override {};
    void actualizar(Entidad *) override;
    void enter(Entidad *entidad) override;

};

#endif //FINAL_FIGHT_AGACHADO_H
