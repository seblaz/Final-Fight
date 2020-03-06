//
// Created by sebas on 7/11/19.
//

#ifndef FINAL_FIGHT_INTERPRETEPUNTUACIONCLI_H
#define FINAL_FIGHT_INTERPRETEPUNTUACIONCLI_H

#include <sstream>
#include "../modelos/PuntuacionJugadores.h"
#include "InterpreteCliente.h"

using namespace std;

class InterpretePuntuacionCli:public InterpreteCliente
{

private:
  PuntuacionJugadores * puntuacion;

public:
  explicit InterpretePuntuacionCli (PuntuacionJugadores * puntuacion);
  void interpretar (stringstream & s) override;

};


#endif //FINAL_FIGHT_INTERPRETEPUNTUACIONCLI_H
