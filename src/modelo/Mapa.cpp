//
// Created by sebas on 30/8/19.
//

#include <algorithm>
#include "Mapa.h"
#include "../servicios/Locator.h"
#include "serializables/EstadoDePersonaje.h"
#include "serializables/Energia.h"

using namespace std;

IdEntidad
  Mapa::ultimoId = 0;

Entidad *
Mapa::crearEntidad ()
{
  auto *e = new Entidad ();
  entidades[++ultimoId] = e;
  return e;
}

Entidad *
Mapa::crearEntidadConId (IdEntidad idEntidad)
{
  auto *e = new Entidad ();
  entidades[idEntidad] = e;
  return e;
}

vector < Entidad * >Mapa::devolverEntidades ()
{
  vector < Entidad * >values (entidades.size ());
  auto
    value_selector =[](auto pair) {
    return pair.second;
  };
  transform (entidades.begin (), entidades.end (), values.begin (),
	     value_selector);
  return values;
}

void
Mapa::vaciarMapa ()
{
  entidades.clear ();
  colisionables.clear ();
  personajes.clear ();
  enemigos.clear ();
  elementos.clear ();
  armas.clear ();
  Locator::logger ()->log (DEBUG, "Se vació el vector de entidades.");
for (auto tupla:jugadores.getJugadores ())
    {
      entidades[tupla.first] = tupla.second;
      personajes.push_back (tupla.second);
      colisionables.push_back (tupla.second);
      Locator::logger ()->log (DEBUG,
			       "Se agregó al jugador con id de entidad " +
			       to_string (tupla.first) + " a las entidades.");
    }
}

void
Mapa::agregarJugadorConId (IdEntidad idEntidad, Entidad * jugador)
{
  jugadores.agregarJugador (idEntidad, jugador);
}

Entidad *
Mapa::getEntidad (IdEntidad idEntidad)
{
  return entidades[idEntidad];
}

bool
Mapa::contiene (IdEntidad idEntidad)
{
  return !(entidades.find (idEntidad) == entidades.end ());
}

unordered_map < IdEntidad, Entidad * >Mapa::devolverEntidadesConId ()
{
  return entidades;
}

Jugadores *
Mapa::getJugadores ()
{
  return &jugadores;
}


void
Mapa::guardarSerializado (stringstream & s)
{
  lock_guard < mutex > lock (m);
  serializadoMasReciente = move (s);
}

void
Mapa::serializar (ostream & stream)
{
  lock_guard < mutex > lock (m);
  stream << serializadoMasReciente.str ();
}

Entidad *
Mapa::crearJugador ()
{
  Entidad *jugador = crearEntidad ();
  jugadores.agregarJugador (ultimoId, jugador);
  personajes.push_back (jugador);
  colisionables.push_back (jugador);
  return jugador;
}

Entidad *
Mapa::crearEnemigo ()
{
  auto *enemigo = crearEntidad ();
  enemigos.push_back (enemigo);
  colisionables.push_back (enemigo);
  return enemigo;
}

Entidad *
Mapa::crearElemento ()
{
  auto *elemento = crearEntidad ();
  elementos.push_back (elemento);
  colisionables.push_back (elemento);
  return elemento;
}

Entidad *
Mapa::crearArma ()
{
  auto *arma = crearEntidad ();
  armas.push_back (arma);
  return arma;
}

Entidad *
Mapa::crearEscenario ()
{
  return crearEntidad ();
}

Entidad *
Mapa::crearTransicion ()
{
  return crearEntidad ();
}

vector < Entidad * >&Mapa::getPersonajes ()
{
  return personajes;
}

vector < Entidad * >&Mapa::getEnemigos ()
{
  return enemigos;
}

vector < Entidad * >&Mapa::getElementos ()
{
  return elementos;
}

vector < Entidad * >&Mapa::getArmas ()
{
  return armas;
}

vector < Entidad * >&Mapa::getColisionables ()
{
  return colisionables;
}

void
Mapa::quitarPersonaje (Entidad * enemigo)
{
  colisionables.erase (remove
		       (colisionables.begin (), colisionables.end (),
			enemigo), colisionables.end ());
  enemigos.erase (remove (enemigos.begin (), enemigos.end (), enemigo),
		  enemigos.end ());
  personajes.erase (remove (personajes.begin (), personajes.end (), enemigo),
		    personajes.end ());
}

void
Mapa::quitarElemento (Entidad * elemento)
{
  colisionables.erase (remove
		       (colisionables.begin (), colisionables.end (),
			elemento), colisionables.end ());
  elementos.erase (remove (elementos.begin (), elementos.end (), elemento),
		   elementos.end ());
}

void
Mapa::quitarArma (Entidad * arma)
{
  colisionables.erase (remove
		       (colisionables.begin (), colisionables.end (), arma),
		       colisionables.end ());
  armas.erase (remove (armas.begin (), armas.end (), arma), armas.end ());
}

int
Mapa::enemigosAtacando ()
{
  int maximoDeAtacantes = 0;
for (auto * enemigo:enemigos)
    {
      auto *estado =
	enemigo->getEstado < EstadoDePersonaje > ("estado de personaje");

      if (estado->getEstado () != MUERTO && estado->getEstado () != REPOSANDO)
	{
	  maximoDeAtacantes++;
	}

    }
  return maximoDeAtacantes;
}
