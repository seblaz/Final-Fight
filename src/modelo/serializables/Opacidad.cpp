//
// Created by franco on 12/10/19.
//

#include "Opacidad.h"

void
Opacidad::setOpacidad (int opacidad)
{
  this->opacidad = opacidad;
}

int
Opacidad::getOpacidad ()
{
  return opacidad;
}

void
Opacidad::serializar (ostream & stream)
{
  serializarEntero (stream, opacidad);
}

void
Opacidad::deserializar (istream & stream)
{
  opacidad = deserializarEntero (stream);
}
