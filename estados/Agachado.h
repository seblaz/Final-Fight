//
// Created by franco on 8/9/19.
//

#ifndef FINAL_FIGHT_AGACHADO_H
#define FINAL_FIGHT_AGACHADO_H

#include "EstadoDePersonaje.h"
#include <SDL_scancode.h>
#include "Parado.h"
#include "../servicios/Logger.h"

class Agachado : public EstadoDePersonaje {

public:
    Agachado();
    ~Agachado();
    void actualizar(Entidad *) override;
    void enter(Entidad* entidad) override;
    void agachar(Entidad *) override  {};
};

#endif //FINAL_FIGHT_AGACHADO_H
