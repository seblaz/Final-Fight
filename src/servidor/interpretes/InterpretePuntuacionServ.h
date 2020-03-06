//
// Created by sebas on 7/11/19.
//

#ifndef FINAL_FIGHT_INTERPRETEPUNTUACIONSERV_H
#define FINAL_FIGHT_INTERPRETEPUNTUACIONSERV_H


#include "InterpreteServidor.h"
#include "../etapas/Etapa.h"

class InterpretePuntuacionServ:public InterpreteServidor
{

private:
  IdEtapa siguienteEtapa;

public:
  explicit InterpretePuntuacionServ (Usuario * usuario,
				     IdEtapa siguienteEtapa);
  bool interpretarAccion (ACCION accion, stringstream & s) override;
  void finalizarCliente () override;

};

class ConfirmarSeleccionPuntuacion:public EventoAProcesar
{

private:
  IdEtapa siguienteEtapa;

public:
  explicit ConfirmarSeleccionPuntuacion (IdEtapa siguienteEtapa);
  void resolver () override;

};

#endif //FINAL_FIGHT_INTERPRETEPUNTUACIONSERV_H
