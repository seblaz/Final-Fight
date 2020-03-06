//
// Created by sebas on 5/10/19.
//

#include "Procesamiento.h"
#include "../servicios/Locator.h"

EventosAProcesar *
Procesamiento::devolverCola ()
{
  return &eventosAProcesar;
}

void
Procesamiento::procesar ()
{
  while (!fin)
    {
      auto *evento = eventosAProcesar.pop ();
      evento->resolver ();
      delete evento;
    }
  Locator::logger ()->log (DEBUG, "Se termina el hilo de procesamiento.");
}

void
Procesamiento::finalizar ()
{
  fin = true;
  eventosAProcesar.push (new EventoVacio ());
}

pthread_t
Procesamiento::procesarEnHilo ()
{
  Locator::logger ()->log (DEBUG, "Se creó el hilo de procesamiento.");
  return lanzarHilo (bind (&Procesamiento::procesar, this));
}
