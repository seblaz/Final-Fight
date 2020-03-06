//
// Created by sebas on 7/11/19.
//

#include "InterpretePuntuacionCli.h"
#include "../../usuario/Usuario.h"
#include "../../modelo/serializables/Puntaje.h"

InterpretePuntuacionCli::InterpretePuntuacionCli (PuntuacionJugadores * puntuacion):
puntuacion
  (puntuacion)
{
}

void
InterpretePuntuacionCli::interpretar (stringstream & s)
{
  while (s.rdbuf ()->in_avail () != 0)
    {
      Usuario usuario;
      usuario.deserializar (s);
      Puntaje puntaje;
      puntaje.deserializar (s);
      puntuacion->setPuntuacion (usuario.getUsuario (),
				 puntaje.obtenerPuntos ());
    }
}
