//
// Created by sebas on 5/11/19.
//

#include "ModeloJuego.h"
#include "../../servicios/Locator.h"

void
ModeloJuego::serializar (ostream & stream)
{
  Locator::mapa ()->serializar (stream);
}
