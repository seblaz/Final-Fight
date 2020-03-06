//
// Created by sebas on 9/10/19.
//

#include "EventoPersonaje.h"
#include "../estados/personajes/EstadoDePersonajeServidor.h"
#include "../modelo/serializables/Energia.h"

EventoPersonaje::EventoPersonaje (Entidad * personaje):personaje (personaje)
{
}

void
Reposar::resolver ()
{
  personaje->getComportamiento < EstadoDePersonajeServidor >
    ("estado")->reposar ();
}

void
Saltar::resolver ()
{
  personaje->getComportamiento < EstadoDePersonajeServidor >
    ("estado")->saltar ();
}

void
Golpear::resolver ()
{
  personaje->getComportamiento < EstadoDePersonajeServidor >
    ("estado")->darGolpe ();
}

void
Agachar::resolver ()
{
  personaje->getComportamiento < EstadoDePersonajeServidor >
    ("estado")->agachar ();
}

void
CaminarIzquierda::resolver ()
{
  personaje->getComportamiento < EstadoDePersonajeServidor >
    ("estado")->caminar (0, 1, 0, 0);
}

void
CaminarDerecha::resolver ()
{
  personaje->getComportamiento < EstadoDePersonajeServidor >
    ("estado")->caminar (1, 0, 0, 0);
}

void
CaminarArriba::resolver ()
{
  personaje->getComportamiento < EstadoDePersonajeServidor >
    ("estado")->caminar (0, 0, 1, 0);
}

void
CaminarAbajo::resolver ()
{
  personaje->getComportamiento < EstadoDePersonajeServidor >
    ("estado")->caminar (0, 0, 0, 1);
}

void
CaminarIzquierdaArriba::resolver ()
{
  personaje->getComportamiento < EstadoDePersonajeServidor >
    ("estado")->caminar (0, 1, 1, 0);
}

void
CaminarIzquierdaAbajo::resolver ()
{
  personaje->getComportamiento < EstadoDePersonajeServidor >
    ("estado")->caminar (0, 1, 0, 1);
}

void
CaminarDerechaArriba::resolver ()
{
  personaje->getComportamiento < EstadoDePersonajeServidor >
    ("estado")->caminar (1, 0, 1, 0);
}

void
CaminarDerechaAbajo::resolver ()
{
  personaje->getComportamiento < EstadoDePersonajeServidor >
    ("estado")->caminar (1, 0, 0, 1);
}

void
ModoTest::resolver ()
{
  personaje->getEstado < Energia > ("energia")->cambiarModoTest ();
}
