//
// Created by sebas on 5/11/19.
//

#ifndef FINAL_FIGHT_INTERPRETESERVIDOR_H
#define FINAL_FIGHT_INTERPRETESERVIDOR_H

#include <sstream>
#include "../../modelo/serializables/Accion.h"
#include "../../usuario/Usuario.h"
#include "../../eventos/Eventos.h"

using namespace std;

class Etapa;

class InterpreteServidor
{

private:
  Usuario * usuario;
  Etapa *etapa = nullptr;
  void desconectarUsuarioVoluntariamente ();

public:
    explicit InterpreteServidor (Usuario * usuario);
  Usuario *getUsuario ();
  Etapa *getEtapa ();
  void setEtapa (Etapa * etapa);
  bool interpretarStream (stringstream & s);
  virtual bool interpretarAccion (ACCION accion, stringstream & s) = 0;
  virtual void iniciar ()
  {
  };
  virtual void finalizarCliente ()
  {
  };

};

class DesconectarVoluntariamente:public EventoAProcesar
{

private:
  Usuario * usuario;

public:
  explicit DesconectarVoluntariamente (Usuario * usuario);
  void resolver () override;
};

#endif //FINAL_FIGHT_INTERPRETESERVIDOR_H
