//
// Created by franco on 13/9/19.
//

#ifndef FINAL_FIGHT_CAMINANDO_H
#define FINAL_FIGHT_CAMINANDO_H

#include "EstadoDePersonajeServidor.h"
#include <SDL_scancode.h>


class Caminando:public EstadoDePersonajeServidor
{

public:
  using EstadoDePersonajeServidor::EstadoDePersonajeServidor;
  void caminar (bool X_pos, bool X_neg, bool Y_pos, bool Y_neg) override;
  void actualizar () override
  {
  };

};

#endif //FINAL_FIGHT_CAMINANDO_H
