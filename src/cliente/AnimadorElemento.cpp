//
// Created by sebas on 15/11/19.
//

#include "AnimadorElemento.h"
#include "../modelo/serializables/Elemento.h"
#include "../graficos/FabricaDeAnimacionesCliente.h"

void
AnimadorElemento::actualizar ()
{
  auto *elemento = entidad->getEstado < Elemento > ("elemento");
  auto *fabricaDeAnimaciones =
    entidad->getEstado < FabricaDeAnimacionesCliente >
    ("fabrica de animaciones");
  entidad->agregarEstado ("animacion",
			  fabricaDeAnimaciones->getAnimacion (elemento->
							      estaRoto ()?
							      "/roto" :
							      "/sano"));
}
