//
// Created by franco on 17/11/19.
//

#include "BossIA.h"
#include "../../servicios/Locator.h"
#include "../personajes/EstadoDePersonajeServidor.h"

BossIA::BossIA (Entidad * entidad, Jugadores * jugadores):
Comportamiento (entidad), jugadores (jugadores)
{
}

void
BossIA::actualizar ()
{
  if (ciclo > 200)
    {
      ciclo = 0;
    }
  ciclo++;
  Locator::eventos ()->push (new EventoBossIA (jugadores, entidad, ciclo));
}

EventoBossIA::EventoBossIA (Jugadores * jugadores, Entidad * entidad,
			    int ciclo):
entidad (entidad),
jugadores (jugadores),
ciclo (ciclo)
{
}

void
EventoBossIA::resolver ()
{
  auto *estado =
    entidad->getComportamiento < EstadoDePersonajeServidor > ("estado");
  auto *estadoDePersonaje =
    entidad->getEstado < EstadoDePersonaje > ("estado de personaje");

  auto *posicion = entidad->getEstado < Posicion > ("posicion");
  auto posicionMasCercana = jugadores->posicionMasCercana (posicion);

  Posicion restaPosicion = posicion->menos (&posicionMasCercana);
  float mod = restaPosicion.modulo ();
  float modX = restaPosicion.moduloX ();
  float modY = restaPosicion.moduloY ();
  if (mod <= 1000)
    {
      if (mod >= 600)
	{
	  if (ciclo > 180)
	    {
	      estado->saltar ();
	    }
	  else
	    {
	      estado->caminar (restaPosicion.x <= 0, restaPosicion.x > 0,
			       restaPosicion.y < 0, restaPosicion.y > 0);
	    }
	}
      else
	{
	  if (ciclo < 70 && modX >= 200)
	    {
	      estado->caminar (restaPosicion.x <= 0, restaPosicion.x > 0,
			       restaPosicion.y < 0, restaPosicion.y > 0);
	    }
	  else if (estadoDePersonaje->getEstado () == CAMINANDO && modX > 90
		   && modX < 200 && modY < 5 && ciclo < 75)
	    {
	      estado->darGolpe ();
	    }
	  else if (ciclo < 100)
	    {
	      estado->caminar (restaPosicion.x > 0, restaPosicion.x <= 0,
			       restaPosicion.y > 0, restaPosicion.y < 0);
	    }
	  else if (estadoDePersonaje->getEstado () == CAMINANDO
		   && ciclo < 105)
	    {
	      estado->saltar ();
	    }
	  else if (ciclo < 180 && modX >= 200)
	    {
	      estado->caminar (restaPosicion.x <= 0, restaPosicion.x > 0,
			       restaPosicion.y < 0, restaPosicion.y > 0);
	    }
	  else if (estadoDePersonaje->getEstado () == CAMINANDO && modX > 90
		   && modX < 200 && modY < 5 && ciclo < 185)
	    {
	      estado->darGolpe ();
	    }
	  else
	    {
	      estado->caminar (restaPosicion.x > 0, restaPosicion.x <= 0,
			       restaPosicion.y > 0, restaPosicion.y < 0);
	    }
	}
    }
  else
    {
      estado->reposar ();
    }

}
