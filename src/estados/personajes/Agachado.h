//
// Created by franco on 8/9/19.
//

#ifndef FINAL_FIGHT_AGACHADO_H
#define FINAL_FIGHT_AGACHADO_H

#include "EstadoDePersonajeServidor.h"
#include <SDL_scancode.h>
#include "Reposando.h"
#include "../../servicios/Logger.h"

class Agachado : public EstadoDePersonajeServidor {

public:
    using EstadoDePersonajeServidor::EstadoDePersonajeServidor;
    void agachar() override {};
    void actualizar() override;

};

#endif //FINAL_FIGHT_AGACHADO_H
