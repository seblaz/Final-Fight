//
// Created by sebas on 6/11/19.
//

#include <algorithm>
#include "VistaJuego.h"
#include "../../servicios/Locator.h"
#include "../Animador.h"

void
VistaJuego::graficar (SDL_Renderer * renderer)
{

  auto entidades = Locator::mapa ()->devolverEntidadesConId ();
  std::vector < std::pair < IdEntidad, Entidad * >>sorted (entidades.begin (),
							   entidades.end ());
  std::sort (sorted.begin (), sorted.end (),[](auto a, auto b)
	     {
	     int yA =
	     a.second->template getEstado < Posicion > ("posicion")->getY ();
	     int yB =
	     b.second->template getEstado < Posicion > ("posicion")->getY ();
	     if (yA != yB) return yA > yB; return a.first > b.first;}
  );

for (auto entidad:sorted)
    {
      try
      {
	entidad.second->getComportamiento < Animador >
	  ("animador")->actualizar ();
      }
      catch (const std::out_of_range & e)
      {
      }

    for (auto * comportamiento:entidad.second->getComportamientos ())
	{
	  comportamiento->actualizar ();
	}
    }
}

string
VistaJuego::getConfigPathMusica ()
{
  return "/pantallas/juego/musica/src";
}
