//
// Created by sebas on 5/11/19.
//

#ifndef FINAL_FIGHT_MODELONULO_H
#define FINAL_FIGHT_MODELONULO_H


#include "../../modelo/serializables/NombrePantalla.h"
#include "Modelo.h"

class ModeloNulo:public Modelo
{

public:
  void serializar (ostream & stream) override
  {
  };

};


#endif //FINAL_FIGHT_MODELONULO_H
