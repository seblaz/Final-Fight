//
// Created by sebas on 6/11/19.
//

#ifndef FINAL_FIGHT_MODELO_H
#define FINAL_FIGHT_MODELO_H

#include "../../modelo/serializables/Serializable.h"

class Modelo
{

public:
  virtual void serializar (ostream & stream) = 0;

};

#endif //FINAL_FIGHT_MODELO_H
