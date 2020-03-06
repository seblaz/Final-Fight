//
// Created by sebas on 16/11/19.
//

#include "RecibiendoGolpeElemento.h"
#include "Sano.h"

RecibiendoGolpeElemento::RecibiendoGolpeElemento (Entidad * entidad,
						  int framesFaltantes):
EstadoDeElemento (entidad),
framesFaltantes (framesFaltantes)
{
}

void
RecibiendoGolpeElemento::actualizar ()
{
  if (framesFaltantes-- < 1)
    entidad->agregarComportamiento ("estado", new Sano (entidad));
}
