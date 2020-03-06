//
// Created by felipe on 2/11/19.
//


#include "Sonido.h"
#include "../servicios/Locator.h"

Sonido::Sonido (const string & rutaSonido)
{
  Locator::logger ()->log (DEBUG, "Se va a buscar el sonido: " + rutaSonido);
  chunk = Mix_LoadWAV (rutaSonido.c_str ());
  if (!chunk)
    Locator::logger ()->log (DEBUG,
			     "Fallo al cargar el sonido: %s\n" +
			     string (Mix_GetError ()));
}

Mix_Chunk *
Sonido::getChunk ()
{
  return this->chunk;
}
