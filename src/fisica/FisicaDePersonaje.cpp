//
// Created by sebas on 2/9/19.
//

#include "FisicaDePersonaje.h"
#include "../modelo/serializables/Orientacion.h"


FisicaDePersonaje::FisicaDePersonaje (Entidad * entidad):Comportamiento
  (entidad)
{
}

void
FisicaDePersonaje::actualizar ()
{
  auto *velocidad = entidad->getEstado < Velocidad > ("velocidad");
  auto *posicion = entidad->getEstado < Posicion > ("posicion");
  auto *orientacion = entidad->getEstado < Orientacion > ("orientacion");
  posicion->mover (*velocidad);
  orientacion->adelante =
    velocidad->x != 0 ? velocidad->x > 0 : orientacion->adelante;
}
