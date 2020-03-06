//
// Created by sebas on 6/11/19.
//

#include "MenuSeleccion.h"

enum PERSONAJE
MenuSeleccion::getPersonaje ()
{
  return actual;
}

void
MenuSeleccion::siguiente ()
{
  actual =
    static_cast < enum PERSONAJE >((static_cast < int >(actual) + 1) %4);
}

void
MenuSeleccion::anterior ()
{
  int pos =
    (static_cast < int >(actual) - 1) == -1 ? 3 : static_cast <
    int >(actual) - 1;
  actual = static_cast < enum PERSONAJE >(pos);
}

void
MenuSeleccion::confirmar ()
{
  listo_ = true;
}

bool
MenuSeleccion::listo ()
{
  return listo_;
}
