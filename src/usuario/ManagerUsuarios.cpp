//
// Created by leandro on 7/10/19.
//

#include "ManagerUsuarios.h"
#include "../servicios/Locator.h"
#include <algorithm>

ManagerUsuarios::ManagerUsuarios (int max):
maximo (max)
{
  cargarUsuarios ();
}

void
ManagerUsuarios::cargarUsuarios ()
{
  Configuracion *config = Locator::configuracion ();
  int cantidad = config->getIntValue ("/usuarios/cantidad");
  for (int i = 0; i < cantidad; i++)
    {
      string user =
	config->getValue ("/usuarios/usuario" + to_string (i) + "/username");
      string password =
	config->getValue ("/usuarios/usuario" + to_string (i) + "/password");
      baseUsuarios[user] = password;
    }
}

void
ManagerUsuarios::agregarUsuario (Usuario * nuevoUsuario)
{
  Locator::logger ()->log (DEBUG,
			   "Se agrega el usuario: " +
			   nuevoUsuario->getUsuario ());
  usuarios.push_back (nuevoUsuario);
  Locator::logger ()->log (INFO,
			   "Faltan " + to_string (maximo - usuarios.size ()) +
			   " jugadoresMax.");
}

bool
ManagerUsuarios::estaPresente (Usuario * usuario)
{
  auto pos =
    find_if (usuarios.begin (), usuarios.end (),[&usuario] (Usuario * u) {
	     return u->getUsuario () == usuario->getUsuario ();}
  );
  return pos != usuarios.end ();
}

list < Usuario * >ManagerUsuarios::getUsuarios ()
{
  return usuarios;
}

Usuario *
ManagerUsuarios::getUsuarioAnterior (Usuario * usuario)
{
  auto pos =
    find_if (usuarios.begin (), usuarios.end (),[&usuario] (Usuario * u) {
	     return u->getUsuario () == usuario->getUsuario ();}
  );
  return *pos;
}

void
ManagerUsuarios::reemplazarUsuarioCon (Usuario * usuario)
{
  auto pos =
    find_if (usuarios.begin (), usuarios.end (),[&usuario] (Usuario * u) {
	     return u->getUsuario () == usuario->getUsuario ();}
  );
  *pos = usuario;
}

bool
ManagerUsuarios::faltanJugadores ()
{
  return usuarios.size () < maximo;
}

bool
ManagerUsuarios::hayJugadoresConectados ()
{
  int desconectados = 0;

  std::list < Usuario * >::iterator it;
  for (it = usuarios.begin (); it != usuarios.end (); ++it)
    {
      if (it.operator* ()->estaDesconectadoVoluntariamente ())
	{
	  desconectados++;
	}
    }
  return desconectados < this->maximo;
}

bool
ManagerUsuarios::validarContrasenia (Usuario * usuario)
{
  return (baseUsuarios.find (usuario->getUsuario ()) != baseUsuarios.end ())
    && (baseUsuarios[usuario->getUsuario ()] == usuario->getContrasenia ());
}
