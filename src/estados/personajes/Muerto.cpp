//
// Created by franco on 15/11/19.
//

#include "Muerto.h"
#include "../../modelo/serializables/Energia.h"

void
Muerto::actualizar ()
{
  if (framesFaltantes-- <= 0
      && entidad->getEstado < Energia > ("energia")->revivir ())
    {
      EstadoDePersonajeServidor::reposar ();
    }
}
