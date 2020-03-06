//
// Created by sebas on 20/10/19.
//

#include "EstadoDePersonaje.h"

EstadoDePersonaje::EstadoDePersonaje ():estado (REPOSANDO)
{
}

EstadoDePersonaje::EstadoDePersonaje (ESTADO_DE_PERSONAJE estado):estado
  (estado)
{
}

ESTADO_DE_PERSONAJE
EstadoDePersonaje::getEstado ()
{
  return estado;
}

void
EstadoDePersonaje::serializar (ostream & stream)
{
  serializarEntero (stream, estado);
}

void
EstadoDePersonaje::deserializar (istream & stream)
{
  estado =
    static_cast < enum ESTADO_DE_PERSONAJE >(deserializarEntero (stream));
}

string
EstadoDePersonaje::estadoACadena (ESTADO_DE_PERSONAJE e)
{
  switch (e)
    {
    case CAMINANDO:
      return "caminando";
    case SALTANDO:
      return "saltando";
    case SALTANDO_CON_MOVIMIENTO:
      return "saltandoAdelante";
    case REPOSANDO:
      return "reposando";
    case DANDO_GOLPE:
      return "dandoGolpe";
    case AGACHADO:
      return "agachado";
    case PATEANDO:
      return "pateando";
    case RECIBIENDO_GOLPE:
      return "recibiendoGolpe";
    case MUERTO:
      return "muerto";
    };
}
