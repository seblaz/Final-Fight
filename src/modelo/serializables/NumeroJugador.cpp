//
// Created by sebas on 30/8/19.
//


#include "NumeroJugador.h"

NumeroJugador::NumeroJugador ():numeroJugador (1)
{
}

NumeroJugador::NumeroJugador (int numeroJugador)
{
  this->numeroJugador = numeroJugador;
}

void
NumeroJugador::serializar (ostream & stream)
{
  serializarEntero (stream, numeroJugador);
}

void
NumeroJugador::deserializar (istream & stream)
{
  numeroJugador = deserializarEntero (stream);
}
