//
// Created by franco on 13/9/19.
//

#include "Caminando.h"
#include "../../servicios/Locator.h"

#define RAPIDEZ 4

void
Caminando::caminar (bool X_pos, bool X_neg, bool Y_pos, bool Y_neg)
{
  auto *velocidad = entidad->getEstado < Velocidad > ("velocidad");

  velocidad->x = RAPIDEZ * X_pos - RAPIDEZ * X_neg;
  velocidad->y = RAPIDEZ * Y_pos - RAPIDEZ * Y_neg;
}
