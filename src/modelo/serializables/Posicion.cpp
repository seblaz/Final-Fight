//
// Created by sebas on 30/8/19.
//

#include <cmath>
#include "Posicion.h"
#include "../../servicios/Locator.h"

Posicion::Posicion (int x, int y, int z):
x (x),
y (y),
z (z)
{
}

void
Posicion::mover (Velocidad & velocidad)
{
  float velocidadRelativa =
    Locator::configuracion ()->getFloatValue ("/velocidad/juego", 1);
  x = x + int (velocidad.x * velocidadRelativa);
  y = y + int (velocidad.y * velocidadRelativa);
  z = z + int (velocidad.z * velocidadRelativa);
}

int
Posicion::getX ()
{
  return x;
}

int
Posicion::getY ()
{
  return y;
}

int
Posicion::getZ ()
{
  return z;
}

Posicion
Posicion::operator- (const Posicion & otraPosicion)
{
  return Posicion (x - otraPosicion.x, y - otraPosicion.y,
		   z - otraPosicion.z);
}

void
Posicion::setX (int xNuevo)
{
  x = xNuevo;
}

void
Posicion::serializar (ostream & stream)
{
  serializarEntero (stream, x);
  serializarEntero (stream, y);
  serializarEntero (stream, z);
}

void
Posicion::deserializar (istream & stream)
{
  x = deserializarEntero (stream);
  y = deserializarEntero (stream);
  z = deserializarEntero (stream);
}

bool
Posicion::operator== (const Posicion & otraPosicion)
{
  return (x == otraPosicion.x) && (y == otraPosicion.y)
    && (z == otraPosicion.z);
}

bool
Posicion::operator< (const Posicion & otraPosicion)
{
  return (x < otraPosicion.x && y < otraPosicion.y && z < otraPosicion.z);
}

int
Posicion::distanciaEntrePuntos (Posicion * otraPosicion)
{
  return sqrt ((x - otraPosicion->x) * (x - otraPosicion->x) +
	       (y - otraPosicion->y) * (y - otraPosicion->y));
}

float
Posicion::modulo ()
{
  return sqrt ((x * x) + (y * y));
}

Posicion
Posicion::menos (Posicion * otraPosicion)
{
  return Posicion (x - otraPosicion->x, y - otraPosicion->y,
		   z - otraPosicion->z);
}

float
Posicion::moduloX ()
{
  return sqrt ((x * x));
}

float
Posicion::moduloY ()
{
  return sqrt ((y * y));
}
