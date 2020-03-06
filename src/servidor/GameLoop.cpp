//
// Created by sebas on 7/10/19.
//

#include "GameLoop.h"
#include "../servicios/Locator.h"
#include "../eventos/ActualizarYSerializarMapa.h"
#include <unistd.h>

void
GameLoop::loop ()
{
  const size_t MS_PER_FRAME = 1.0 / Locator::configuracion ()->getIntValue ("/fps") * 1000 * 1000;	// Microsegundos.

  while (Locator::usuarios ()->hayJugadoresConectados ())
    {
      Locator::eventos ()->
	push (new ActualizarYSerializarMapa (Locator::mapa ()));
      usleep (MS_PER_FRAME);
    }
  Locator::logger ()->log (INFO,
			   "Todos los usuarios se desconectaron voluntariamente.");
}
