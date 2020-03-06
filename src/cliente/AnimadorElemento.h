//
// Created by sebas on 15/11/19.
//

#ifndef FINAL_FIGHT_ANIMADORELEMENTO_H
#define FINAL_FIGHT_ANIMADORELEMENTO_H


#include "../modelo/Entidad.h"

class AnimadorElemento:public Comportamiento
{

public:
  using Comportamiento::Comportamiento;
  void actualizar () override;

};


#endif //FINAL_FIGHT_ANIMADORELEMENTO_H
