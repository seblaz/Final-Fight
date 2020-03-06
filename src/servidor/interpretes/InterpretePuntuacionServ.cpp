//
// Created by sebas on 7/11/19.
//

#include "InterpretePuntuacionServ.h"

#include "../../servicios/Locator.h"
#include "../NivelServidor.h"
#include "../../modelo/serializables/Actividad.h"

bool
InterpretePuntuacionServ::interpretarAccion (ACCION accion, stringstream & s)
{
  if (accion == CONFIRMAR)
    Locator::eventos ()->
      push (new ConfirmarSeleccionPuntuacion (siguienteEtapa));

  return true;
}

InterpretePuntuacionServ::InterpretePuntuacionServ (Usuario * usuario, IdEtapa siguienteEtapa):
InterpreteServidor (usuario),
siguienteEtapa (siguienteEtapa)
{
}

void
InterpretePuntuacionServ::finalizarCliente ()
{
  getUsuario ()->desconectar ();
  getUsuario ()->getPersonaje ()->getEstado < Actividad >
    ("actividad")->activo = false;
}

ConfirmarSeleccionPuntuacion::ConfirmarSeleccionPuntuacion (IdEtapa siguienteEtapa):
siguienteEtapa
  (siguienteEtapa)
{
}

void
ConfirmarSeleccionPuntuacion::resolver ()
{
  if (siguienteEtapa == "nivel2")
    NivelServidor::generarNivel ("nivel2", Locator::mapa ());
  Locator::clientes ()->cambiarTodosA (siguienteEtapa);
}
