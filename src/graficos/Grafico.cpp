//
// Created by sebas on 21/9/19.
//

#include <SDL_rect.h>
#include "Grafico.h"
#include "../servicios/Locator.h"
#include "AnimacionCliente.h"
#include "Sprite.h"
#include "../modelo/serializables/Orientacion.h"

SDL_Rect
calcularPosicionEnPantalla (Posicion posicionEnMapa,
			    SDL_Rect posicionEnSprite,
			    float esacalaDeAnimacion)
{
  Configuracion *config = Locator::configuracion ();

  float escala =
    config->getFloatValue ("/escala/entidades") * esacalaDeAnimacion;

  const int screenX = int (round ((float) posicionEnMapa.getX ()
				  - (float) posicionEnSprite.w / 2 * escala));

  const int screenY =
    int (round
	 ((float) config->getIntValue ("/resolucion/alto") -
	  (float) posicionEnMapa.getZ () - (float) posicionEnMapa.getY () -
	  (float) posicionEnSprite.h * escala));

  SDL_Rect posicionEnPantalla = { screenX,
    screenY,
    int ((float) posicionEnSprite.w * escala),
    int ((float) posicionEnSprite.h * escala)
  };

  return posicionEnPantalla;
}


Grafico::Grafico (Entidad * entidad):Comportamiento (entidad)
{
}

void
Grafico::actualizar ()
{
  auto *posicion = entidad->getEstado < Posicion > ("posicion");
  int posicionDeEscenarioX = Locator::posicionEscenario ()->x;
  int dif = posicion->x - posicionDeEscenarioX;

  if (dif > -200
      && dif <
      Locator::configuracion ()->getIntValue ("/resolucion/ancho") + 200)
    {
      SDL_Renderer *renderer = Locator::renderer ();
      auto *animacion = entidad->getEstado < AnimacionCliente > ("animacion");
      auto *sprite = entidad->getEstado < Sprite > ("sprite");
      auto *orientacion = entidad->getEstado < Orientacion > ("orientacion");

      Posicion nuevaPosicion (posicion->getX () - posicionDeEscenarioX,
			      posicion->getY (), posicion->getZ ());
      SDL_Rect posicionEnSprite = animacion->devolverPosicion (entidad);
      SDL_Rect posicionEnPantalla =
	calcularPosicionEnPantalla (nuevaPosicion, posicionEnSprite,
				    animacion->escala ());

      if ((orientacion != nullptr) && (!orientacion->adelante))
	{
	  SDL_RenderCopyEx (renderer, sprite->getTexture (),
			    &posicionEnSprite, &posicionEnPantalla, 180,
			    nullptr, SDL_FLIP_VERTICAL);
	}
      else
	{
	  SDL_RenderCopy (renderer, sprite->getTexture (), &posicionEnSprite,
			  &posicionEnPantalla);
	}
    }
}
