//
// Created by leandro on 7/10/19.
//

#include "Usuario.h"

#include <utility>

Usuario::Usuario ():personajeSeleccionado (NULO)
{
};

Usuario::Usuario (string usuario, string contrasenia):
usuario (std::move (usuario)), contrasenia (std::move (contrasenia))
{
}

string
Usuario::getUsuario ()
{
  return usuario;
}

string
Usuario::getContrasenia ()
{
  return contrasenia;
}

//void Usuario::setSocket(Socket *nuevoSocket) {
//    socket = nuevoSocket;
//}
//
//Socket *Usuario::getSocket() {
//    return socket;
//}

bool
Usuario::estaConectado ()
{
//    return socket != nullptr;
  return conectado;
}

void
Usuario::desconectar ()
{
//    socket = nullptr;
  conectado = false;
}

void
Usuario::setValido (bool valido)
{
  valido_ = valido;
}

bool
Usuario::getValido ()
{
  return valido_;
}

void
Usuario::setPersonaje (Entidad * pEntidad)
{
  personaje = pEntidad;
}

Entidad *
Usuario::getPersonaje ()
{
  return personaje;
}

void
Usuario::setPersonajeSeleccionado (enum PERSONAJE personajeSeleccionado_)
{
  personajeSeleccionado = personajeSeleccionado_;
};

enum PERSONAJE
Usuario::getPersonajeSeleccionado ()
{
  return personajeSeleccionado;
}

bool
Usuario::operator== (const Usuario & obj)
{
  return usuario == obj.usuario;
}

void
Usuario::serializar (ostream & stream)
{
  serializarString (stream, usuario);
  serializarString (stream, contrasenia);
}

void
Usuario::deserializar (istream & stream)
{
  usuario = deserializarString (stream);
  contrasenia = deserializarString (stream);
}

void
Usuario::desconectarVoluntariamente ()
{
  desconectar ();
  desconectadoVoluntariamente = true;
}

bool
Usuario::estaDesconectadoVoluntariamente ()
{
  return desconectadoVoluntariamente;
}
