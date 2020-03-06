//
// Created by sebas on 26/11/19.
//

#include "InterpreteGameOver.h"
#include "../../servicios/Locator.h"

bool
InterpreteGameOver::interpretarAccion (ACCION accion, stringstream & s)
{
  if (accion == CONFIRMAR)
    Locator::eventos ()->push (new ConfirmarSeleccionGameOver ());
  return true;
}

void
ConfirmarSeleccionGameOver::resolver ()
{
  Locator::clientes ()->cambiarTodosA ("puntuacion2");
}
