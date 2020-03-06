//
// Created by sebas on 8/11/19.
//

#ifndef FINAL_FIGHT_INTERPRETENULO_H
#define FINAL_FIGHT_INTERPRETENULO_H


#include "InterpreteServidor.h"

class InterpreteNulo:public InterpreteServidor
{

public:
  using InterpreteServidor::InterpreteServidor;
  bool interpretarAccion (ACCION accion, stringstream & s) override;

};


#endif //FINAL_FIGHT_INTERPRETENULO_H
