//
// Created by franco on 29/10/19.
//

#include "BuscarJugadores.h"

BuscarJugadores::BuscarJugadores (Entidad * entidad, Jugadores * jugadores):
Comportamiento (entidad), jugadores (jugadores)
{
}

void
BuscarJugadores::actualizar ()
{
  if (ciclo > 100)
    {
      ciclo = 0;
    }
  ciclo++;
  Locator::eventos ()->
    push (new EventoBuscarJugadores (jugadores, entidad, ciclo));
}

EventoBuscarJugadores::EventoBuscarJugadores (Jugadores * jugadores,
					      Entidad * entidad, int ciclo):
entidad (entidad),
jugadores (jugadores),
ciclo (ciclo)
{
}

void
EventoBuscarJugadores::resolver ()
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
  if (mod <= 900)
    {
      if (mod >= 600)
	{
	  estado->caminar (restaPosicion.x <= 0, restaPosicion.x > 0,
			   restaPosicion.y < 0, restaPosicion.y > 0);
	}
      else
	{
	  if (ciclo < 65 && modX >= 120)
	    {
	      estado->caminar (restaPosicion.x <= 0, restaPosicion.x > 0,
			       restaPosicion.y < 0, restaPosicion.y > 0);
	    }
	  else if (estadoDePersonaje->getEstado () == CAMINANDO && modX > 90
		   && modX < 120 && modY < 5 && ciclo < 70)
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
