//
// Created by sebas on 8/11/19.
//

#ifndef FINAL_FIGHT_ENTRADANULA_H
#define FINAL_FIGHT_ENTRADANULA_H


#include <SDL_events.h>
#include "../../modelo/serializables/Accion.h"
#include "EntradaUsuario.h"

class EntradaNula:public EntradaUsuario
{

public:
  Accion * getAccion (SDL_Event * e) override;

};


#endif //FINAL_FIGHT_ENTRADANULA_H
