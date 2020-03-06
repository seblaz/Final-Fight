//
// Created by sebas on 7/11/19.
//

#include "EntradaConfirmacion.h"

Accion *
EntradaConfirmacion::getAccion (SDL_Event * e)
{
  if (e->type == SDL_KEYDOWN && e->key.keysym.scancode == SDL_SCANCODE_RETURN)
    {
      return new Accion (CONFIRMAR);
    }
  return new Accion (NULA);
}
