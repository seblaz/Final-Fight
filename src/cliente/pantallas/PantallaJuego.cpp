//
// Created by sebas on 6/11/19.
//

#include "PantallaJuego.h"


PantallaJuego::PantallaJuego (IdPantalla id, InterpreteCliente * interprete, EntradaUsuario * entradaUsuario, Vista * vista):
Pantalla (id, interprete, entradaUsuario,
	  vista)
{
}

void
PantallaJuego::iniciar ()
{
  Pantalla::iniciar ();
  receptor.recibirEnHilo ();
}

void
PantallaJuego::recibir (stringstream & s)
{
  receptor.devolverStreamMasReciente (s);
}

void
PantallaJuego::finalizar ()
{
  Pantalla::finalizar ();
  receptor.finalizar ();
}
