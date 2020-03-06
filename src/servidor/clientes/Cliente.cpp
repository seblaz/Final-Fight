//
// Created by sebas on 5/11/19.
//

#include "Cliente.h"
#include "ManagerClientes.h"
#include "../../servicios/Locator.h"
#include "../modelo/ModeloAutenticacion.h"
#include "../interpretes/InterpreteAutenticacionServ.h"
#include "../modelo/ModeloNulo.h"
#include "../interpretes/InterpreteMenuSeleccionServ.h"
#include "../modelo/ModeloJuego.h"
#include "../interpretes/InterpreteJuegoServ.h"
#include "../modelo/ModeloPuntuacion.h"
#include "../interpretes/InterpretePuntuacionServ.h"
#include "../interpretes/InterpreteNulo.h"
#include "../interpretes/InterpreteGameOver.h"
#include <unistd.h>
#include <functional>


Cliente::Cliente (Socket * socket):
socket (socket)
{
  auto *modeloAutenticacion = new ModeloAutenticacion ();
  auto *interpreteAutenticacion =
    new InterpreteAutenticacionServ (usuario, modeloAutenticacion);
  etapas.agregar (new
		  Etapa ("autenticacion", modeloAutenticacion,
			 interpreteAutenticacion));
  etapas.agregar (new
		  Etapa ("menu de seleccion", new ModeloNulo (),
			 new InterpreteMenuSeleccionServ (usuario)));
  etapas.agregar (new
		  Etapa ("nivel1", new ModeloJuego (),
			 new InterpreteJuegoServ (usuario)));
  etapas.agregar (new
		  Etapa ("puntuacion1", new ModeloPuntuacion (),
			 new InterpretePuntuacionServ (usuario, "nivel2")));
  etapas.agregar (new
		  Etapa ("nivel2", new ModeloJuego (),
			 new InterpreteJuegoServ (usuario)));
  etapas.agregar (new
		  Etapa ("puntuacion2", new ModeloPuntuacion (),
			 new InterpretePuntuacionServ (usuario, "fin")));
  etapas.agregar (new
		  Etapa ("fin", new ModeloNulo (),
			 new InterpreteNulo (usuario)));
  etapas.agregar (new
		  Etapa ("game over", new ModeloNulo (),
			 new InterpreteGameOver (usuario)));

  lanzarHilo (bind (&Cliente::transmitirEnHilo, this));
  lanzarHilo (bind (&Cliente::recibirEnHilo, this));
}

void
Cliente::setManager (ManagerClientes * manager_)
{
  manager = manager_;
}

void
Cliente::cambiarA (const IdEtapa & etapa)
{
  etapas.cambiarA (etapa);
}

void
Cliente::recibirEnHilo ()
{
  Locator::logger ()->log (DEBUG,
			   "Se inicia el hilo de recepción para un cliente.");
  stringstream s;
  do
    {
      s.str (std::string ());
      if (socket->estaDesconectado () || !socket->recibir (s))
	{
	  Locator::logger ()->log (ERROR,
				   "Se detecta socket invalido en el hilo de recepción y se cierra.");
	  break;
	}
    }
  while (!fin
	 && etapas.getActual ()->getInterprete ()->interpretarStream (s));

  etapas.getActual ()->finalizarCliente ();
  Locator::logger ()->log (DEBUG, "Se termina el hilo de recepción.");
}

void
Cliente::transmitirEnHilo ()
{
  Locator::logger ()->log (DEBUG,
			   "Se inicia el hilo de transmisión para un cliente.");
  const size_t MS_PER_FRAME = 1.0 / Locator::configuracion ()->getIntValue ("/fps") * 1000 * 1000;	// Microsegundos.
  stringstream s;
  do
    {
      s.str (std::string ());
      etapas.getActual ()->serializar (s);
      if (socket->estaDesconectado () || !socket->enviar (s))
	{
	  Locator::logger ()->log (ERROR,
				   "Se detecta socket invalido en el hilo de transmisión y se cierra.");
	  fin = true;
	  break;
	}
      usleep (MS_PER_FRAME);
    }
  while (!fin);

  Locator::logger ()->log (DEBUG, "Se termina el hilo de transmisión.");
  manager->quitarCliente (this);
  socket->finalizarConexion ();
}
