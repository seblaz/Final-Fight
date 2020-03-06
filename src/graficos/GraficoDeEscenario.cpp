//
// Created by sebas on 10/9/19.
//

#include "GraficoDeEscenario.h"
#include "../servicios/Locator.h"
#include "../modelo/serializables/Posicion.h"

#include <utility>
#include <cmath>

GraficoDeEscenario::GraficoDeEscenario (Entidad * entidad,
					vector < SDL_Texture * >sprites,
					vector < SDL_Rect > posicionesSprite,
					vector < float >distanciasAlFondo,
					float escalaHorizontal):
Comportamiento (entidad),
sprites (std::move (sprites)),
escalaHorizontal (escalaHorizontal),
posicionesSprite (std::move (posicionesSprite)),
distanciasAlFondo (std::move (distanciasAlFondo))
{
}

void
GraficoDeEscenario::actualizar ()
{
  SDL_Renderer *renderer = Locator::renderer ();
  int alto = Locator::configuracion ()->getIntValue ("/resolucion/alto");
  int ancho = Locator::configuracion ()->getIntValue ("/resolucion/ancho");
  int posicion = entidad->getEstado < Posicion > ("posicion")->getX ();

  for (size_t i = 0; i < sprites.size (); ++i)
    {
      SDL_Texture *sprite = sprites[i];
      SDL_Rect posicionSprite = posicionesSprite[i];
      posicionSprite.w = int (round ((float) ancho / escalaHorizontal));
      posicionSprite.x =
	int (round
	     ((float) posicion / escalaHorizontal * distanciasAlFondo[i]));
      SDL_Rect posicionEscenario = { 0, 0, ancho, alto };

      SDL_RenderCopy (renderer, sprite, &posicionSprite, &posicionEscenario);
    }
}
