//
// Created by sebas on 5/11/19.
//

#include "NombrePantalla.h"

#include <utility>

NombrePantalla::NombrePantalla ():
id ("")
{
}

NombrePantalla::NombrePantalla (IdEtapa id):
id (id)
{
}

void
NombrePantalla::setId (IdEtapa id_)
{
  id = std::move (id_);
}

IdEtapa
NombrePantalla::getId ()
{
  return id;
}

void
NombrePantalla::serializar (ostream & stream)
{
  serializarString (stream, id);
}

void
NombrePantalla::deserializar (istream & stream)
{
  id = deserializarString (stream);
}
