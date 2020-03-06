//
// Created by sebas on 6/11/19.
//

#include "EntradaMenuSeleccion.h"
#include "../../servicios/Locator.h"

Accion *
EntradaMenuSeleccion::getAccion (SDL_Event * e)
{
  if (framesInactivo == 0)
    {
      if (!menu->listo ())
	{
	  const Uint8 *entrada = SDL_GetKeyboardState (nullptr);

	  if (entrada[SDL_SCANCODE_LEFT])
	    {
	      menu->anterior ();
	      framesInactivo = framesPorAccion;

	    }
	  else if (entrada[SDL_SCANCODE_RIGHT])
	    {
	      menu->siguiente ();
	      framesInactivo = framesPorAccion;

	    }
	  else if (entrada[SDL_SCANCODE_RETURN])
	    {
	      Locator::logger ()->log (DEBUG, "Se selecciono enter.");
	      menu->confirmar ();
	      return new Accion (static_cast < ACCION >
				 (SELECCIONAR_GUY + static_cast <
				  int >(menu->getPersonaje ())));
	    }
	}
    }
  else
    {
      framesInactivo--;
    }
  return new Accion (NULA);
}

EntradaMenuSeleccion::EntradaMenuSeleccion (MenuSeleccion * menu):
menu (menu)
{
}
