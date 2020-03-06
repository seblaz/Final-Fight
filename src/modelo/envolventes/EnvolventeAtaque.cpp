//
// Created by sebas on 11/11/19.
//

#include "EnvolventeAtaque.h"

EnvolventeAtaque::EnvolventeAtaque (Posicion * posicion, int ancho,
				    int profundidad,
				    Orientacion * orientacion):
orientacion (orientacion),
Envolvente (posicion, ancho, profundidad)
{
}

bool
EnvolventeAtaque::colisionaCon (EnvolventeVolumen * envolvente, Arma * arma)
{
  int mod = orientacion->adelante ? 1 : -1;
  int nuevoAncho = ancho + arma->getAncho ();
  return abs (posicion->x + ((nuevoAncho * mod) / 2) -
	      envolvente->posicion->x) <
    ((nuevoAncho / 2) + envolvente->ancho)
    && abs (posicion->y - envolvente->posicion->y) <
    (profundidad + envolvente->profundidad);

}
