//
// Created by felipe on 22/9/19.
//

#include "Patrullar.h"
#include "../../servicios/Locator.h"

Patrullar::Patrullar (Entidad * entidad):Comportamiento (entidad)
{
  srand (time (nullptr));
  Logger *
    logger = Locator::logger ();
  logger->log (DEBUG, "Se instancio un objeto de clase Patrullar");
}

Patrullar::~Patrullar ()
{
  Logger *logger = Locator::logger ();
  logger->log (DEBUG, "Se elimino un objeto de clase Patrullar");
}

#define RAPIDEZ 4

void
Patrullar::actualizar ()
{

  auto *estado =
    entidad->getComportamiento < EstadoDePersonajeServidor > ("estado");

  int num = 1 + rand () % (101 - 1);

  estado->caminar (adelante, !adelante, 0, 0);

  if (pasosTotales < contadorDePasos && num > 95)
    {
      adelante = !adelante;
      contadorDePasos = 0;
      estado->saltar ();
    }
  contadorDePasos++;
}
